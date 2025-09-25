# WdfRequestRetrieveOutputMemory function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestRetrieveOutputMemory** method retrieves a handle to a framework memory object that represents an I/O request's output buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Memory` [out]

A pointer to a location that receives a handle to a framework memory object.

## Return value

**WdfRequestRetrieveOutputMemory** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request type is not valid or the request is using [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers). For more information about supported methods for accessing data buffers, see the following Remarks section. |
| **STATUS_INTERNAL_ERROR** | The request has already been completed. |
| **STATUS_BUFFER_TOO_SMALL** | The output buffer's length is zero. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A request's output buffer receives information, such as data from a disk, that the driver provides to the originator of the request. Your driver can call **WdfRequestRetrieveOutputMemory** to obtain the output buffer for a read request or a device I/O control request, but not for a write request (because write requests do not provide output data).

The **WdfRequestRetrieveOutputMemory** method retrieves the output buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method or the [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method for accessing data buffers. If the request's I/O control code is [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control), or if the request came from another kernel-mode driver, **WdfRequestRetrieveOutputMemory** also supports I/O requests that use [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

If **WdfRequestRetrieveOutputMemory** returns STATUS_SUCCESS, the driver receives a handle to a framework memory object that represents the output buffer. To access the buffer, the driver must call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

The driver can access the retrieved framework memory object until it [completes the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) that the *Request* parameter represents.

Instead of calling **WdfRequestRetrieveOutputMemory**, the driver can call [WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer), which retrieves the buffer's address and length.

For more information about **WdfRequestRetrieveOutputMemory**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example shows how an [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function can obtain a handle to the framework memory object that represents a read request's output buffer. The example then formats and sends the read request to a USB I/O target.

```cpp
VOID
MyEvtIoRead(
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
    // The driver previously stored a pipe handle in
    // the device object's context space.
    //
    pDeviceContext = GetDeviceContext(WdfIoQueueGetDevice(Queue));
    pipe = pDeviceContext->BulkReadPipe;

    //
    // Get output memory.
    //
    status = WdfRequestRetrieveOutputMemory(
                                            Request,
                                            &reqMemory
                                            );
    if(!NT_SUCCESS(status)){
        goto Exit;
    }
    //
    // Format the request.
    //
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
    //
    // Send the request.
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
    //
    // Complete the request now if an error occurred.
    //
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

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory)

[WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer)