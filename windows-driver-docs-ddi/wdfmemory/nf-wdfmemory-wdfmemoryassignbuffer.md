# WdfMemoryAssignBuffer function

## Description

[Applies to KMDF and UMDF]

The **WdfMemoryAssignBuffer** method assigns a specified buffer to a memory object that a driver created by calling [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated).

## Parameters

### `Memory` [in]

A handle to a framework memory object that was obtained by calling [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated).

### `Buffer` [in]

A pointer to a driver-supplied buffer.

### `BufferSize` [in]

The nonzero size, in bytes, of the buffer that *Buffer* points to.

## Return value

**WdfMemoryAssignBuffer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The method can assign a buffer to a memory object that [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) created, but not to a memory object that [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) created.

The buffer that the *Buffer* parameter points to can be allocated from the pageable or non-pageable memory pool. If the driver allocates the buffer from the pageable pool, or if the buffer is from pageable pool because it came from a user-mode application, the driver must access the buffer only at IRQL < DISPATCH_LEVEL. (Note that the driver's [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions, if provided, can be called at IRQL <= DISPATCH_LEVEL.)

For more information about framework memory objects, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

#### Examples

The following code example allocates a buffer and then assigns the buffer to a framework memory object.

```cpp
PVOID  pNewBuffer = NULL;

pNewBuffer = ExAllocatePoolWithTag(
                                   NonPagedPool,
                                   NEW_BUFFER_SIZE,
                                   MY_DRIVER_TAG
                                   );
if (pNewBuffer == NULL){
    goto Error;
}

status = WdfMemoryAssignBuffer(
                               memHandle,
                               pNewBuffer,
                               NEW_BUFFER_SIZE
                               );
```

## See also

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)