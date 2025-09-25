# MEMORYSTATUS structure

## Description

Contains information about the current state of both physical and virtual memory. The
[GlobalMemoryStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalmemorystatus) function stores information in a
**MEMORYSTATUS** structure.

## Members

### `dwLength`

The size of the
**MEMORYSTATUS** data structure, in bytes. You do not need to set this member before calling the
[GlobalMemoryStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalmemorystatus) function; the function sets it.

### `dwMemoryLoad`

A number between 0 and 100 that specifies the approximate percentage of physical memory that is in use (0 indicates no memory use and 100 indicates full memory use).

### `dwTotalPhys`

The amount of actual physical memory, in bytes.

### `dwAvailPhys`

The amount of physical memory currently available, in bytes. This is the amount of physical memory that can be immediately reused without having to write its contents to disk first. It is the sum of the size of the standby, free, and zero lists.

### `dwTotalPageFile`

The current size of the committed memory limit, in bytes. This is physical memory plus the size of the page file, minus a small overhead.

### `dwAvailPageFile`

The maximum amount of memory the current process can commit, in bytes. This value should be smaller than the system-wide available commit. To calculate this value, call [GetPerformanceInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getperformanceinfo) and subtract the value of **CommitTotal** from **CommitLimit**.

### `dwTotalVirtual`

The size of the user-mode portion of the virtual address space of the calling process, in bytes. This value depends on the type of process, the type of processor, and the configuration of the operating system. For example, this value is approximately 2 GB for most 32-bit processes on an x86 processor and approximately 3 GB for 32-bit processes that are large address aware running on a system with 4 GT RAM Tuning enabled.

### `dwAvailVirtual`

The amount of unreserved and uncommitted memory currently in the user-mode portion of the virtual address space of the calling process, in bytes.

## Remarks

**MEMORYSTATUS** reflects the state of memory at the time of the call. It also reflects the size of the paging file at that time. The operating system can enlarge the paging file up to the maximum size set by the administrator.

On computers with more than 4 GB of memory, the
**MEMORYSTATUS** structure can return incorrect information, reporting a value of –1 to indicate an overflow. If your application is at risk for this behavior, use the
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function instead of the
[GlobalMemoryStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalmemorystatus) function.

#### Examples

For an example, see the
[GlobalMemoryStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalmemorystatus) function.

## See also

[GlobalMemoryStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalmemorystatus)

[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))