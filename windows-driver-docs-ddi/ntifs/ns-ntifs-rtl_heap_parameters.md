## Description

The **RTL_HEAP_PARAMETERS** structure contains parameters to be applied when creating a heap.

## Members

### `Length`

Size, in bytes, of the **RTL_HEAP_PARAMETERS** structure.

### `SegmentReserve`

Segment reserve size, in bytes. If this value is not specified, 1 MB is used.

### `SegmentCommit`

Segment commit size, in bytes. If this value is not specified, PAGE_SIZE * 2 is used.

### `DeCommitFreeBlockThreshold`

Decommit free block threshold, in bytes. If this value is not specified, PAGE_SIZE is used.

### `DeCommitTotalFreeThreshold`

Decommit total free threshold, in bytes. If this value is not specified, 65536 is used.

### `MaximumAllocationSize`

Size, in bytes, of the largest block of memory that can be allocated from the heap. If this value is not specified, the difference between the highest and lowest addresses, less one page, is used.

### `VirtualMemoryThreshold`

Virtual memory threshold, in bytes. If this value is not specified, or if it is greater than the maximum heap block size, the maximum heap block size of 0x7F000 is used.

### `InitialCommit`

Initial amount of memory, in bytes, to commit for the heap. Must be less than or equal to **InitialReserve**. If **HeapBase** and **CommitRoutine** are non-NULL, this parameter, which overrides the value of **CommitSize**, must be a nonzero value; otherwise it is ignored.

### `InitialReserve`

Initial amount of memory, in bytes, to reserve for the heap. If **HeapBase** and **CommitRoutine** are non-NULL, this parameter, which overrides the value of **ReserveSize**, must be a nonzero value; otherwise it is ignored.

### `CommitRoutine`

Pointer to a [**RTL_HEAP_COMMIT_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-rtl_heap_commit_routine) routine to commit pages from the heap. If this parameter is non-NULL, the heap must be nongrowable. If **HeapBase** is NULL, **CommitRoutine** must also be NULL.

### `Reserved`

Reserved for system use. Drivers must set this parameter to zero.

## See also

[**RTL_HEAP_COMMIT_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-rtl_heap_commit_routine)
[**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)