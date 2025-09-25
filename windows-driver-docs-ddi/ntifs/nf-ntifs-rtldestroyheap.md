# RtlDestroyHeap function

## Description

The **RtlDestroyHeap** routine destroys the specified heap object. **RtlDestroyHeap** decommits and releases all the pages of a private heap object, and it invalidates the handle to the heap.

## Parameters

### `HeapHandle` [in]

Handle for the heap to be destroyed. This parameter is a heap handle returned by **RtlCreateHeap**.

## Return value

If the call to **RtlDestroyHeap** succeeds, the return value is a **NULL** pointer.

If the call to **RtlDestroyHeap** fails, the return value is a handle for the heap.

## Remarks

Processes can call **RtlDestroyHeap** without first calling **RtlFreeHeap** to free memory that was allocated from the heap.

## See also

[RtlAllocateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap)

[RtlCreateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)

[RtlFreeHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeheap)