# WdfRequestRetrieveOutputBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestRetrieveOutputBuffer** method retrieves an I/O request's output buffer.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `MinimumRequiredSize` [in]

The minimum buffer size, in bytes, that the driver needs to process the I/O request.

### `Buffer` [out]

A pointer to a location that receives the buffer's address.

### `Length` [out, optional]

A pointer to a location that receives the buffer's size, in bytes. This parameter is optional and can be **NULL**.

## Return value

**WdfRequestRetrieveOutputBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_BUFFER_TOO_SMALL** | The output buffer's length is zero, or the *MinimumRequiredSize* parameter specifies a buffer size that is larger than the buffer's actual size. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request type is not valid or the request is using [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers). For more information about supported methods for accessing data buffers, see the following Remarks section. |
| **STATUS_INTERNAL_ERROR** | The request has already been completed. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A request's output buffer receives information, such as data from a disk, that the driver provides to the originator of the request. Your driver can call **WdfRequestRetrieveOutputBuffer** to obtain the output buffer for a read request or a device I/O control request, but not for a write request (because write requests do not provide output data).

The **WdfRequestRetrieveOutputBuffer** method retrieves the output buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method or the [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers) method for accessing data buffers. If the request's I/O control code is [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control), or if the request came from another kernel-mode driver, **WdfRequestRetrieveOutputBuffer** also supports I/O requests that use [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

If **WdfRequestRetrieveOutputBuffer** returns STATUS_SUCCESS, the driver receives the address and, optionally, the size of the output buffer.

The driver can access the retrieved buffer until it [completes the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) that the *Request* parameter represents.

Instead of calling **WdfRequestRetrieveOutputBuffer**, the driver can call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory), which creates a framework memory object that represents the buffer.

For more information about **WdfRequestRetrieveOutputBuffer**, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example is part of an [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) callback function. This example obtains a USB device's configuration descriptor and places the descriptor in the I/O request's output buffer.

```cpp
VOID
MyEvtIoDeviceControl(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  OutputBufferLength,
    IN size_t  InputBufferLength,
    IN ULONG  IoControlCode
    )
{
    WDFDEVICE  device;
    PDEVICE_CONTEXT  pDevContext;
    size_t  bytesReturned = 0;
    NTSTATUS  status;

    device = WdfIoQueueGetDevice(Queue);
    //
    // GetDeviceContext is a driver-defined function
    // to retrieve device object context space.
    //
    pDevContext = GetDeviceContext(device);

    switch(IoControlCode) {

      case IOCTL_OSRUSBFX2_GET_CONFIG_DESCRIPTOR: {

        PUSB_CONFIGURATION_DESCRIPTOR  configurationDescriptor = NULL;
        USHORT  requiredSize;

        //
        // First, get the size of the USB configuration descriptor.
        //
        status = WdfUsbTargetDeviceRetrieveConfigDescriptor(
                                                pDevContext->UsbDevice,
                                                NULL,
                                                &requiredSize
                                                );
        if (status == STATUS_BUFFER_TOO_SMALL) {
            break;
        }

        //
        // Get the buffer. Make sure the buffer is big
        // enough to hold the configuration descriptor.
        //
        status = WdfRequestRetrieveOutputBuffer(
                                                Request,
                                                (size_t)requiredSize,
                                                &configurationDescriptor,
                                                NULL
                                                );
        if(!NT_SUCCESS(status)){
            break;
        }
        //
        // Now get the config descriptor.
        //
        status = WdfUsbTargetDeviceRetrieveConfigDescriptor(
                                                pDevContext->UsbDevice,
                                                configurationDescriptor,
                                                &requiredSize
                                                );
        if (!NT_SUCCESS(status)) {
            break;
        }

        bytesReturned = requiredSize;
      }
        break;
...
    (Other case statements removed.)
...
    default:
        status = STATUS_INVALID_DEVICE_REQUEST;
        break;
    }
    //
    // Complete the request.
    //
    WdfRequestCompleteWithInformation(
                                      Request,
                                      status,
                                      bytesReturned
                                      );
    return;
}
```

## See also

[WdfRequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)