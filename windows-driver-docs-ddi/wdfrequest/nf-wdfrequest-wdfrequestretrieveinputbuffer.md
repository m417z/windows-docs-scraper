# WdfRequestRetrieveInputBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestRetrieveInputBuffer** method retrieves an I/O request's input buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `MinimumRequiredLength`

The minimum buffer size, in bytes, that the driver needs to process the I/O request.

### `Buffer` [out]

A pointer to a location that receives the buffer's address.

### `Length` [out, optional]

A pointer to a location that receives the buffer's size, in bytes. This parameter is optional and can be **NULL**.

## Return value

**WdfRequestRetrieveInputBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_BUFFER_TOO_SMALL** | The input buffer's length is zero, or the *MinimumRequiredSize* parameter specifies a buffer size that is larger than the buffer's actual size. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request type is not valid or the request is using [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers). For more information about supported methods for accessing data buffers, see the following Remarks section. |
| **STATUS_INTERNAL_ERROR** | The request has already been completed. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A request's input buffer contains information, such as data to be written to a disk, that was supplied by the originator of the request. Your driver can call **WdfRequestRetrieveInputBuffer** to obtain the input buffer for a write request or a device I/O control request, but not for a read request (because read requests do not provide input data).

The **WdfRequestRetrieveInputBuffer** method retrieves the input buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method or the [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method for accessing data buffers. If the request's I/O control code is [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control), or if the request came from another kernel-mode driver, **WdfRequestRetrieveInputBuffer** also supports I/O requests that use [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

If **WdfRequestRetrieveInputBuffer** returns STATUS_SUCCESS, the driver receives the address and, optionally, the size of the input buffer.

The driver can access the retrieved buffer until it [completes the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) that the *Request* parameter represents.

Instead of calling **WdfRequestRetrieveInputBuffer**, the driver can call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory), which creates a framework memory object that represents the buffer.

For more information about **WdfRequestRetrieveInputBuffer**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example is part of the [Serial](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver's [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function. If the I/O control code is IOCTL_SERIAL_SET_TIMEOUT, the driver obtains new time-out values from the I/O request's input buffer.

```cpp
VOID
SerialEvtIoDeviceControl(
    IN WDFQUEUE     Queue,
    IN WDFREQUEST   Request,
    IN size_t       OutputBufferLength,
    IN size_t       InputBufferLength,
    IN ULONG        IoControlCode
    )
{
    PVOID  buffer;
    size_t  bufSize;

    switch (IoControlCode) {
...

        case IOCTL_SERIAL_SET_TIMEOUTS: {

            PSERIAL_TIMEOUTS NewTimeouts;

            Status = WdfRequestRetrieveInputBuffer(
                                                   Request,
                                                   sizeof(SERIAL_TIMEOUTS),
                                                   &buffer,
                                                   &bufSize
                                                   );
            if (!NT_SUCCESS(Status)) {
                break;
            }

            NewTimeouts =(PSERIAL_TIMEOUTS)buffer;
    }
...
}
```

## See also

[WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory)

[WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer)

[WdfUsbTargetDeviceRetrieveConfigDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceretrieveconfigdescriptor)