# WdfUsbTargetPipeFormatRequestForWrite function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeFormatRequestForWrite** method builds a write request for a USB output pipe, but it does not send the request.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `WriteMemory` [in, optional]

A handle to a framework memory object. This object represents a buffer that contains data that will be sent to the pipe. For more information about this buffer, see the following Remarks section.

### `WriteOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the write buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the buffer, and the transfer size is the buffer size.

## Return value

**WdfUsbTargetPipeFormatRequestForWrite** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | An invalid memory descriptor was specified, the pipe's type was not valid, the transfer direction was invalid, or the specified I/O request was already queued to an I/O target. |
| **STATUS_INTEGER_OVERFLOW** | The offset that the *Offset* parameter specified was invalid. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetPipeFormatRequestForWrite**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send write requests either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetPipeWriteSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipewritesynchronously) method to send write requests synchronously.

The specified pipe must be an output pipe, and the pipe's [type](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-get_type) must be **WdfUsbPipeTypeBulk** or **WdfUsbPipeTypeInterrupt**.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfUsbTargetPipeFormatRequestForWrite** method's *Request* parameter.
2. Use the received request's input buffer for the **WdfUsbTargetPipeFormatRequestForWrite** method's *WriteMemory* parameter.

   The driver must call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to a framework memory object that represents the request's input buffer and use that handle as the value for *WriteMemory*.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Create a new request object and supply its handle for the **WdfUsbTargetPipeFormatRequestForWrite** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide buffer space, and supply the buffer's handle for the **WdfUsbTargetPipeFormatRequestForWrite** method's *WriteMemory* parameter.

   Your driver must specify this buffer space as a WDFMEMORY handle to framework-managed memory. Your driver can do either of the following:

   * Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to create a new memory buffer, if you want the driver to pass a new buffer to the I/O target.
   * Call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to the memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target.Note that if your driver calls [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) and passes the memory handle to **WdfUsbTargetPipeFormatRequestForWrite**, the driver must not complete the received I/O request until after the driver deletes, reuses, or reformats the new, driver-created request object. (**WdfUsbTargetPipeFormatRequestForWrite** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)

After calling **WdfUsbTargetPipeFormatRequestForWrite** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfUsbTargetPipeFormatRequestForWrite** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetPipeFormatRequestForWrite**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetPipeFormatRequestForWrite** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeFormatRequestForWrite** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example is from the [kmdf_fx2](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example is an [EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write) callback function that forwards a write request to a USB pipe. The example calls [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain the request's input buffer, and then it formats the write request so that the request can be sent to a USB pipe. Next, the example registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function. Finally, it sends the request to the USB pipe.

```cpp
VOID
OsrFxEvtIoWrite(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    NTSTATUS  status;
    WDFUSBPIPE  pipe;
    WDFMEMORY  reqMemory;
    PDEVICE_CONTEXT  pDeviceContext;

    if (Length > TEST_BOARD_TRANSFER_BUFFER_SIZE) {
        status = STATUS_INVALID_PARAMETER;
        goto Exit;
    }

    pDeviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));

    pipe = pDeviceContext->BulkWritePipe;

    status = WdfRequestRetrieveInputMemory(
                                           Request,
                                           &reqMemory
                                           );
    if (!NT_SUCCESS(status)){
        goto Exit;
    }

    status = WdfUsbTargetPipeFormatRequestForWrite(
                                                   pipe,
                                                   Request,
                                                   reqMemory,
                                                   NULL
                                                   );
    if (!NT_SUCCESS(status)) {
        goto Exit;
    }

    WdfRequestSetCompletionRoutine(
                                   Request,
                                   EvtRequestWriteCompletionRoutine,
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
}
```

## See also

[WdfUsbTargetPipeFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforread)