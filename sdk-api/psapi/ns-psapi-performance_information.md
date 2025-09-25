# PERFORMANCE_INFORMATION structure

## Description

Contains performance information.

## Members

### `cb`

The size of this structure, in bytes.

### `CommitTotal`

The number of pages currently committed by the system. Note that committing pages (using [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) with MEM_COMMIT) changes this value immediately; however, the physical memory is not charged until the pages are accessed.

### `CommitLimit`

The current maximum number of pages that can be committed by the system without extending the paging file(s). This number can change if memory is added or deleted, or if pagefiles have grown, shrunk, or been added. If the paging file can be extended, this is a soft limit.

### `CommitPeak`

The maximum number of pages that were simultaneously in the committed state since the last system reboot.

### `PhysicalTotal`

The amount of actual physical memory, in pages.

### `PhysicalAvailable`

The amount of physical memory currently available, in pages. This is the amount of physical memory that can be immediately reused without having to write its contents to disk first. It is the sum of the size of the standby, free, and zero lists.

### `SystemCache`

The amount of system cache memory, in pages. This is the size of the standby list plus the system working set.

### `KernelTotal`

The sum of the memory currently in the paged and nonpaged kernel pools, in pages.

### `KernelPaged`

The memory currently in the paged kernel pool, in pages.

### `KernelNonpaged`

The memory currently in the nonpaged kernel pool, in pages.

### `PageSize`

The size of a page, in bytes.

### `HandleCount`

The current number of open handles.

### `ProcessCount`

The current number of processes.

### `ThreadCount`

The current number of threads.

## See also

[GetPerformanceInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getperformanceinfo)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))