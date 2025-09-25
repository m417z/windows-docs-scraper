# WdfRequestSend function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestSend** method sends a specified I/O request to a specified I/O target.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Target` [in]

A handle to a framework I/O target object. For more information about how to obtain this handle, see the following Remarks section.

### `Options`

A pointer to a [**WDF_REQUEST_SEND_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that contains caller-supplied request options. This parameter is optional and can be **NULL** if you do not want to enable any request options.

## Return value

**WdfRequestSend** returns **TRUE** if the request was sent to the target. Otherwise, this method returns **FALSE**, and calling [**WdfRequestGetStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus) returns a status that fails an NT_SUCCESS() test.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The request object that the driver specifies for the *Request* parameter can be one that it [received](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests) or one that it created by calling the [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) method.

To obtain a handle to an I/O target object, the driver can do one of the following:

* If the driver is using general I/O targets, it calls [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget). For more information, see [Initializing a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target).
* If the driver is using a specialized I/O target, it calls one or more methods that the specialized target object defines. For example, a driver for a USB device can call [WdfUsbTargetDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetiotarget) or [WdfUsbTargetPipeGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipegetiotarget).

By default, **WdfRequestSend** delivers the request to the target asynchronously, which means it returns immediately without waiting for the request to be completed. Optionally, the request can be delivered synchronously, which means **WdfRequestSend** does not return until a driver completes the request. To send the request synchronously, the driver must set the **WDF_REQUEST_SEND_OPTION_SYNCHRONOUS** flag in the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

If **WdfRequestSend** fails, or if your driver sets the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag, the driver can call [WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus) immediately after calling **WdfRequestSend**.

If **WdfRequestSend** succeeds and your driver does not set the WDF_REQUEST_SEND_OPTION_SYNCHRONOUS flag, the driver typically calls [WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus) from within a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.

If the driver sends the request synchronously, we recommend that the driver set a time-out value in the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure and the time-out flag in the **Flags** member of this structure.

If the driver supplies a time-out value, it should call [WdfRequestAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestallocatetimer) before calling **WdfRequestSend**. This ensures that **WdfRequestSend** will not fail if there are insufficient system resources to allocate a timer.

 If the driver sets the **WDF_REQUEST_SEND_OPTION_SYNCHRONOUS** flag, it must call **WdfRequestSend** at IRQL = PASSIVE_LEVEL. If this flag is not set, the driver must call this method at IRQL <= DISPATCH_LEVEL.
**WdfRequestSend** sends the request at the caller's IRQL.

A driver cannot call **WdfRequestSend** to send an I/O request to a USB pipe, if the driver has configured a [continuous reader](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes) for the pipe.

When sending a request to a UMDF driver, a kernel-mode driver must follow the IRQL restrictions outlined in [Supporting Kernel-Mode Clients in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-drivers).

For more information about **WdfRequestSend**, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

#### Examples

The following code example is a shortened version of an [EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write) callback function from the [kmdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver. The function validates the request's buffer length, obtains a handle to the buffer, formats the request for a USB target, and sends the request.

```cpp
VOID
OsrFxEvtIoWrite(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    WDFUSBPIPE  pipe;
    NTSTATUS  status;
    WDFMEMORY  reqMemory;
    PDEVICE_CONTEXT  pDeviceContext;

    UNREFERENCED_PARAMETER(Queue);
    //
    // Check if the transfer size is valid.
    //
    if (Length > MAX_TRANSFER_BUFFER_SIZE) {
        status = STATUS_INVALID_PARAMETER;
        goto Exit;
    }
    //
    // Get driver-defined context space from
    // the device object. The driver stored the
    // pipe handle there.
    //
    pDeviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));
    pipe = pDeviceContext->BulkWritePipe;

    //
    // Get a handle to a memory object that represents
    // the input buffer.
    //
    status = WdfRequestRetrieveInputMemory(Request, &reqMemory);
    if (!NT_SUCCESS(status)){
        goto Exit;
    }
    //
    // Format the request so it can be sent to a USB target.
    //
    status = WdfUsbTargetPipeFormatRequestForWrite(
                            pipe,
                            Request,
                            reqMemory,
                            NULL // Offsets
                            );
    if (!NT_SUCCESS(status)) {
        goto Exit;
    }
    //
    // Set a CompletionRoutine callback function.
    //
    WdfRequestSetCompletionRoutine(
                            Request,
                            EvtRequestReadCompletionRoutine,
                            pipe
                            );
    //
    // Send the request. If an error occurs, complete the request.
    //
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
}
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfRequestAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestallocatetimer)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus)