# WdfMemoryGetBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryGetBuffer** method returns a pointer to the buffer that is associated with a specified memory object.

## Parameters

### `Memory` [in]

A handle to a framework memory object.

### `BufferSize` [out, optional]

A pointer to a location that receives the size, in bytes, of the memory buffer. This parameter is optional and can be **NULL**.

## Return value

**WdfMemoryGetBuffer** returns a pointer to the memory buffer.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

**WdfMemoryGetBuffer** can be called at any IRQL.

#### Examples

The following code example is based on the [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function in the [kmdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver. The example obtains the buffer that is associated with the memory object that the callback function receives. The example copies data from the buffer into device object context space that the driver has defined.

```cpp
VOID
OsrFxEvtUsbInterruptPipeReadComplete(
    WDFUSBPIPE  Pipe,
    WDFMEMORY  Buffer,
    size_t  NumBytesTransferred,
    WDFCONTEXT  Context
    )
{
    PUCHAR  switchState = NULL;
    WDFDEVICE  device;
    PDEVICE_CONTEXT  pDeviceContext = Context;

    device = WdfObjectContextGetObject(pDeviceContext);
    switchState = WdfMemoryGetBuffer(Buffer, NULL);
    pDeviceContext->CurrentSwitchState = *switchState;
}
```

## See also

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfObjectContextGetObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectcontextgetobject)