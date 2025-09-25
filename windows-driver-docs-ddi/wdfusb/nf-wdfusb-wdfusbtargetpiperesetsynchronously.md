# WdfUsbTargetPipeResetSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeResetSynchronously** method builds a reset request and sends it synchronously to a specified USB pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

## Return value

**WdfUsbTargetPipeResetSynchronously** returns the USB I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter specified was incorrect. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was not PASSIVE_LEVEL, or the I/O request that the *Request* parameter specified was already queued to an I/O target. |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfUsbTargetPipeResetSynchronously** method to send a USB reset request synchronously. To send such requests asynchronously use [WdfUsbTargetPipeFormatRequestForReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforreset), followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

Before the framework resets the I/O target's USB pipe, it cancels all I/O requests that remain in the I/O target's queue. The driver must not send additional I/O requests to the I/O target until **WdfUsbTargetPipeResetSynchronously** returns.

The driver must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) before it calls **WdfUsbTargetPipeResetSynchronously**. After **WdfUsbTargetPipeResetSynchronously** returns, the driver can call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart).

When a driver calls **WdfUsbTargetPipeResetSynchronously**, the framework sends a [URB_FUNCTION_RESET_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) request to the I/O target. For more information about resetting a USB pipe, see the USB specification.

The **WdfUsbTargetPipeResetSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter points to, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetPipeResetSynchronously** method's *Request* parameter.

To create and send a new request, either supply a **NULL** request handle for the *Request* parameter, or create a new request object and supply its handle:

* If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
* If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeResetSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example sends a reset request to a USB device's pipe.

```cpp
NTSTATUS  status;

status = WdfUsbTargetPipeResetSynchronously(
                                            Pipe,
                                            WDF_NO_HANDLE,
                                            NULL
                                            );
```

## See also

[WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfUsbTargetPipeAbortSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeabortsynchronously)