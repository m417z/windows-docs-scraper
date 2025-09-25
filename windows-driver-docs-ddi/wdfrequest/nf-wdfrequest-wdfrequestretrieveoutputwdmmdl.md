# WdfRequestRetrieveOutputWdmMdl function

## Description

[Applies to KMDF only]

The **WdfRequestRetrieveOutputWdmMdl** method retrieves a memory descriptor list (MDL) that represents an I/O request's output buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Mdl` [out]

A pointer to a location that receives a pointer to an MDL.

## Return value

**WdfRequestRetrieveOutputWdmMdl** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request type is not valid or the request is using [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers). For more information about supported methods for accessing data buffers, see the following Remarks section. |
| **STATUS_INTERNAL_ERROR** | The request has already been completed. |
| **STATUS_BUFFER_TOO_SMALL** | The input buffer's length is zero. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A request's output buffer receives information, such as data from a disk, that the driver provides to the originator of the request. Your driver can call **WdfRequestRetrieveOutputWdmMdl** for a read request or a device I/O control request, but not for a write request (because write requests do not provide output data).

The **WdfRequestRetrieveOutputWdmMdl** method retrieves the output buffer's MDL for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method or the [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method for accessing data buffers. If the request's I/O control code is [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control), or if the request came from another kernel-mode driver, **WdfRequestRetrieveOutputWdmMdl** also supports I/O requests that use [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

If **WdfRequestRetrieveOutputWdmMdl** returns STATUS_SUCCESS, the driver receives a pointer to an MDL that describes the output buffer.

The driver must not access a request's MDL after [completing the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfRequestRetrieveOutputWdmMdl**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example is part of an [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read) callback function that obtains an MDL for an I/O request's input buffer. If the call to **WdfRequestRetrieveOutputWdmMdl** fails, the driver completes the request with the error status that **WdfRequestRetrieveOutputWdmMdl** returns.

```cpp
VOID
MyDrvEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    NTSTATUS  status;
    PMDL  mdl = NULL;
...
    status = WdfRequestRetrieveOutputWdmMdl(
                                            Request,
                                            &mdl
                                            );
    if (!NT_SUCCESS(status))
    {
        WdfRequestCompleteWithInformation(
                                          Request,
                                          status,
                                          0
                                          );
    }
...
}
```

## See also

[WdfRequestRetrieveInputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputwdmmdl)