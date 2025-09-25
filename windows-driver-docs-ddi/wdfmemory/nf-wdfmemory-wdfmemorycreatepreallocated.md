# WdfMemoryCreatePreallocated function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryCreatePreallocated** method creates a framework memory object for a driver-supplied memory buffer.

## Parameters

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new memory object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Buffer` [in]

A pointer to a driver-supplied buffer.

### `BufferSize` [in]

The nonzero size, in bytes, of the buffer that *Buffer* points to.

### `Memory` [out]

A pointer to a location that receives a handle to the new memory object.

## Return value

**WdfMemoryCreatePreallocated** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |

For a list of other return values that the **WdfMemoryCreatePreallocated** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfMemoryCreatePreallocated** method creates a framework memory object for a buffer that the driver has previously allocated or obtained.

Your driver can call **WdfMemoryCreatePreallocated** if you need to create memory objects that represent pre-existing memory buffers. For example, the driver might receive a driver-defined structure within a buffer for an I/O request that contains an internal I/O control code. The driver can call **WdfMemoryCreatePreallocated** to create a memory object so that the driver can pass the structure to an I/O target.

After a driver has called **WdfMemoryCreatePreallocated**, the driver can call [WdfMemoryAssignBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemoryassignbuffer) to assign a different buffer to the memory object that **WdfMemoryCreatePreallocated** created.

The default parent object for each memory object is the framework driver object that represents the driver that called **WdfMemoryCreatePreallocated**. If your driver creates a memory object that it uses with a specific device object, request object, or other framework object, it should set the memory object's parent appropriately. The memory object will be deleted when the parent object is deleted. If you do not change the default parent object, the memory object will remain in memory until the I/O manager unloads your driver.

A driver can also delete a memory object by calling [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete).

When the framework memory object that **WdfMemoryCreatePreallocated** created is deleted, the framework does not deallocate the pre-existing buffer. Likewise, a call to [WdfMemoryAssignBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemoryassignbuffer) does not deallocate the previously assigned buffer.

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

#### Examples

The following code example allocates a buffer and then creates a framework memory object for the buffer.

```cpp
PVOID  pBuffer = NULL;
WDF_OBJECT_ATTRIBUTES  attributes;
WDFMEMORY  memHandle;

pBuffer = ExAllocatePoolWithTag(
                                NonPagedPool,
                                MY_BUFFER_SIZE,
                                MY_DRIVER_TAG
                                );
if (pBuffer == NULL){
    goto Error;
}
WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = requestHandle;

status = WdfMemoryCreatePreallocated(
                                     &attributes,
                                     pBuffer,
                                     MY_BUFFER_SIZE,
                                     &memHandle
                                     );
```

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfMemoryAssignBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemoryassignbuffer)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreateFromLookaside](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatefromlookaside)