# WdfUsbTargetPipeFormatRequestForReset function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeFormatRequestForReset** method builds a reset request for a specified USB pipe, but it does not send the request.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

## Return value

**WdfUsbTargetPipeFormatRequestForReset** returns the USB I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetPipeFormatRequestForReset**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send a USB reset request either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetPipeResetSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpiperesetsynchronously) method to send a request synchronously.

Before the driver calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), it must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) and it must [complete](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) or [cancel](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) all I/O requests that it has sent to the I/O target. The driver must not send additional I/O requests to the I/O target until the reset request completes.

When a driver calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), the framework sends a [URB_FUNCTION_RESET_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) request to the I/O target. For more information about resetting a USB pipe, see the USB specification.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetPipeFormatRequestForReset** method's *Request* parameter.

To create a new I/O request, call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate a request object. Supply the request handle for the **WdfUsbTargetPipeFormatRequestForReset** method's *Request* parameter. You can reuse the request object by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.

After calling **WdfUsbTargetPipeFormatRequestForReset** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfUsbTargetPipeFormatRequestForReset** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetPipeFormatRequestForReset**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetPipeFormatRequestForReset** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeFormatRequestForReset** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example formats a reset request for a USB pipe, registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the request.

```cpp
status = WdfUsbTargetPipeFormatRequestForReset(
                                               pipe,
                                               Request
                                               );
if (!NT_SUCCESS(status)) {
    goto Exit;
}

WdfRequestSetCompletionRoutine(
                               Request,
                               AbortCompletionRoutine,
                               pipe
                               );

if (WdfRequestSend(
                   Request,
                   WdfUsbTargetPipeGetIoTarget(pipe),
                   WDF_NO_SEND_OPTIONS
                   ) == FALSE) {
    status = WdfRequestGetStatus(Request);
    goto Exit;
}
Exit:
if (!NT_SUCCESS(status)) {
    WdfRequestCompleteWithInformation(
                                      Request,
                                      status,
                                      0
                                      );
}
return;
```

## See also

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)