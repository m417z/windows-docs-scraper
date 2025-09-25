# WdfUsbTargetPipeAbortSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeAbortSynchronously** method builds an abort request and sends it synchronously to a specified USB pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

## Return value

**WdfUsbTargetPipeAbortSynchronously** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter specified was incorrect. |
| **STATUS_INVALID_PARAMETER** | An invalid handle was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was not PASSIVE_LEVEL, or the specified I/O request was already queued to an I/O target. |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfUsbTargetPipeAbortSynchronously** method to send a USB abort request synchronously. To send such requests asynchronously, use [WdfUsbTargetPipeFormatRequestForAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforabort), followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

A USB abort request causes the driver's I/O target to cancel all of the I/O requests that have been sent to a pipe. When a driver calls **WdfUsbTargetPipeAbortSynchronously**, the framework sends a [URB_FUNCTION_ABORT_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) request to the I/O target. For more information about canceling operations on a USB pipe (also called "aborting a pipe"), see the USB specification.

The **WdfUsbTargetPipeAbortSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the *RequestOptions* parameter's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetPipeAbortSynchronously** method's *Request* parameter.

To create and send a new request, either supply a **NULL** request handle for the *Request* parameter, or create a new request object and supply its handle:

* If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
* If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeAbortSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example sends abort requests to all of the pipes that are configured for a USB device's interface.

```cpp
UCHAR  i;
ULONG  count;
NTSTATUS  status;
PDEVICE_CONTEXT  pDevContext;

pDevContext = GetDeviceContext(Device);

count = WdfUsbInterfaceGetNumConfiguredPipes(
                                             pDevContext->UsbInterface
                                             );

for (i = 0; i < count; i++) {
    WDFUSBPIPE pipe;

    pipe = WdfUsbInterfaceGetConfiguredPipe(
                                            pDevContext->UsbInterface,
                                            i,
                                            NULL
                                            );
    status = WdfUsbTargetPipeAbortSynchronously(
                                                pipe,
                                                WDF_NO_HANDLE,
                                                NULL
                                                );
    if (!NT_SUCCESS(status)) {
        break;
    }
}
```

## See also

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfUsbTargetPipeResetSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpiperesetsynchronously)