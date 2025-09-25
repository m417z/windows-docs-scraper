# RtlFreeHeap function

## Description

The **RtlFreeHeap** routine frees a memory block that was allocated from a heap by [RtlAllocateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap).

## Parameters

### `HeapHandle` [in]

A handle for the heap whose memory block is to be freed. This parameter is a handle returned by [RtlCreateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap).

### `Flags` [in, optional]

A set of flags that controls aspects of freeing a memory block. Specifying the following value overrides the corresponding value that was specified in the *Flags* parameter when the heap was created by [RtlCreateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap).

| Flag | Meaning |
| --- | --- |
| HEAP_NO_SERIALIZE | Mutual exclusion will not be used when **RtlFreeHeap** is accessing the heap. |

### `BaseAddress`

A pointer to the memory block to free. This pointer is returned by [**RtlAllocateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap).

## Return value

**RtlFreeHeap** returns **TRUE** if the block was freed successfully;  **FALSE** otherwise.

**Note** Starting with Windows 8 the return value is typed as **LOGICAL**, which has a different size than **BOOLEAN**.

## See also

[RtlAllocateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap)

[RtlCreateHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)

[RtlDestroyHeap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldestroyheap)