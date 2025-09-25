# WdfUsbTargetPipeFormatRequestForRead function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeFormatRequestForRead** method builds a read request for a USB input pipe, but it does not send the request.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `ReadMemory` [in, optional]

A handle to a framework memory object. This object represents a buffer that will receive data from the pipe. The buffer size must be a multiple of the pipe's maximum packet size unless the driver has called [WdfUsbTargetPipeSetNoMaximumPacketSizeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipesetnomaximumpacketsizecheck). For more information about this buffer, see the following Remarks section.

### `ReadOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the read buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the buffer, and the transfer size is the buffer size.

## Return value

**WdfUsbTargetPipeFormatRequestForRead** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | An invalid memory descriptor was specified, the pipe's type was not valid, the transfer direction was invalid, or the specified I/O request was already queued to an I/O target. |
| **STATUS_INTEGER_OVERFLOW** | The offset that the *Offset* parameter specified was invalid. |
| **STATUS_INVALID_BUFFER_SIZE** | The buffer size was not a multiple of the pipe's maximum packet size. The buffer size must be a multiple of the pipe's maximum packet size unless the driver has called [WdfUsbTargetPipeSetNoMaximumPacketSizeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipesetnomaximumpacketsizecheck). |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetPipeFormatRequestForRead**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send read requests either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetPipeReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipereadsynchronously) method to send read requests synchronously.

The pipe that the *Pipe* parameter specifies must be an input pipe, and the pipe's [type](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-get_type) must be **WdfUsbPipeTypeBulk** or **WdfUsbPipeTypeInterrupt**.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfUsbTargetPipeFormatRequestForRead** method's *Request* parameter.
2. Use the received request's output buffer for the **WdfUsbTargetPipeFormatRequestForRead** method's *ReadMemory* parameter.

   The driver must call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's output buffer, and use that handle as the value for the *ReadMemory* parameter.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Create a new request object and supply its handle for the **WdfUsbTargetPipeFormatRequestForRead** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide buffer space, and supply the buffer's handle for the **WdfUsbTargetPipeFormatRequestForRead** method's *ReadMemory* parameter.

   Your driver must specify this buffer space as a WDFMEMORY handle to framework-managed memory. Your driver can do either of the following:

   * Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to create a new memory buffer, if you want the driver to pass a new buffer to the I/O target.
   * Call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to the memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target.Note that if your driver calls [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) and passes the memory handle to **WdfUsbTargetPipeFormatRequestForRead**, the driver must not complete the received I/O request until after the driver deletes, reuses, or reformats the new, driver-created request object. (**WdfUsbTargetPipeFormatRequestForRead** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)

After calling **WdfUsbTargetPipeFormatRequestForRead** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfUsbTargetPipeFormatRequestForRead** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetPipeFormatRequestForRead**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetPipeFormatRequestForRead** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

The framework sets the USBD_SHORT_TRANSFER_OK flag in its internal [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb). Setting this flag allows the last packet of a data transfer to be less than the maximum packet size.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeFormatRequestForRead** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example is from the [kmdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver. This example is an [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function that forwards a read request to a USB pipe. The example calls [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain the request's output buffer, and then it formats the read request so that the request can be sent to a USB pipe. Next, the example registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function. Finally, it sends the request to the USB pipe.

```cpp
VOID
OsrFxEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    WDFUSBPIPE  pipe;
    NTSTATUS  status;
    WDFMEMORY  reqMemory;
    PDEVICE_CONTEXT  pDeviceContext;

    //
    // First, validate input parameters.
    //
    if (Length > TEST_BOARD_TRANSFER_BUFFER_SIZE) {
        status = STATUS_INVALID_PARAMETER;
        goto Exit;
    }

    pDeviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));

    pipe = pDeviceContext->BulkReadPipe;

    status = WdfRequestRetrieveOutputMemory(
                                            Request,
                                            &reqMemory
                                            );
    if (!NT_SUCCESS(status)){
        goto Exit;
    }

    status = WdfUsbTargetPipeFormatRequestForRead(
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
                                   EvtRequestReadCompletionRoutine,
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

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)