## Description

A **RTL_HEAP_COMMIT_ROUTINE** callback routine commits pages from the heap.

## Parameters

### `Base`

Base address for the block of caller-allocated memory being used for the heap.

### `CommitAddress`

Pointer to a variable that will receive the base address of the committed region of pages.

### `CommitSize`

Pointer to a variable that will receive the actual size, in bytes, of the allocated region of pages.

## Return value

**RTL_HEAP_COMMIT_ROUTINE** returns STATUS_SUCCESS or an appropriate error status.

## See also

[**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)

[**RTL_HEAP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters)