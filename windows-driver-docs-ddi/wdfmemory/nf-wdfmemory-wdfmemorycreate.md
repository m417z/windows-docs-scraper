# WdfMemoryCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryCreate** method creates a framework memory object and allocates a memory buffer of a specified size.

## Parameters

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new memory object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed value that specifies the type of memory to be allocated.

### `PoolTag` [in, optional]

A driver-defined pool tag for the allocated memory. Debuggers display this tag. Drivers typically specify a character string of up to four characters, delimited by single quotation marks, in reverse order (for example, 'dcba'). The ASCII value of each character in the tag must be between 0 and 127. Debugging your driver is easier if each pool tag is unique.

If *PoolTag* is zero, the framework provides a default pool tag that uses the first four characters of your driver's kernel-mode service name. If the service name begins with "WDF" (the name is not case sensitive and does not include the quotation marks), the next four characters are used. If fewer than four characters are available, "FxDr" is used.

For KMDF versions 1.5 and later, your driver can use the **DriverPoolTag** member of the [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure to specify a default pool tag.

### `BufferSize` [in]

The nonzero specified size, in bytes, of the buffer.

### `Memory` [out]

A pointer to a location that receives a handle to the new memory object.

### `Buffer` [out, optional]

A pointer to a location that receives a pointer to the buffer that is associated with the new memory object. This parameter is optional and can be **NULL**.

## Return value

**WdfMemoryCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |

For a list of other return values that the **WdfMemoryCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfMemoryCreate** method allocates a buffer of the size that the *BufferSize* parameter specifies and creates a framework memory object that represents the buffer.

To obtain the buffer's address, your driver can supply a non-**NULL** value for the **WdfMemoryCreate** function's *Buffer* parameter, or the driver can call [WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer).

It is good practice to zero memory for memory allocation, especially for allocations that will be copied to an untrusted location (user mode, over the network, etc.) to avoid disclosing sensitive information.
**WdfMemoryCreate** does not zero initialize allocated memory by default.

Based on the driver's usage pattern of the allocated memory, the recommendation for driver writers is to consider:

* [**RtlZeroMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory) immediately after calling **WdfMemoryCreate**
* Or, use a zero-allocation API ([**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2), [**ExAllocatePoolZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero) for kernel mode; [**HeapAlloc**](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc) with the **HEAP_ZERO_MEMORY** flag for user mode), followed by [**WdfMemoryCreatePreallocated**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated). Because pre-allocated buffer is not automatically deleted as part of WDFMEMORY or its parent deletion, this is not the best approach.

The default parent object for each memory object is the framework driver object that represents the driver that called **WdfMemoryCreate**. If your driver creates a memory object that it uses with a specific device object, request object, or other framework object, it should set the memory object's parent appropriately. The memory object and its buffer will be deleted when the parent object is deleted. If you do not change the default parent object, the memory object and its buffer will remain until the I/O manager unloads your driver.

A driver can also delete a memory object and its buffer by calling [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete).

If *BufferSize* is less than PAGE_SIZE, the operating system gives the caller exactly the number of requested bytes of memory. The buffer is not necessarily page-aligned, but it is aligned by the number of bytes that the MEMORY_ALLOCATION_ALIGNMENT constant specifies in *Ntdef.h*.

If *BufferSize* is PAGE_SIZE or greater, for KMDF only the system allocates a page-aligned buffer. If the *PoolType* parameter is **NonPagedPool**, the system allocates the number of pages that are necessary to hold all of the bytes. Any unused bytes on the last-allocated page are essentially wasted.

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

If your driver specifies **PagedPool** for *PoolType*, the **WdfMemoryCreate** method must be called at IRQL <= APC_LEVEL. Otherwise, the method can be called at IRQL <= DISPATCH_LEVEL.

#### Examples

The following code example creates a framework memory object and allocates a buffer whose size is WRITE_BUFFER_SIZE. The memory object's parent is a request object.

```cpp
NTSTATUS  status;
WDF_OBJECT_ATTRIBUTES  attributes;
WDFMEMORY  writeBufferMemHandle;
PVOID  writeBufferPointer;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = requestHandle;
status = WdfMemoryCreate(
                         &attributes,
                         NonPagedPool,
                         0,
                         WRITE_BUFFER_SIZE,
                         &writeBufferMemHandle,
                         &writeBufferPointer
                         );
```

## See also

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfMemoryCreateFromLookaside](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatefromlookaside)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)