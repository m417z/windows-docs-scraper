# MEMORYSTATUSEX structure

## Description

Contains information about the current state of both physical and virtual memory, including extended memory. The
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function stores information in this structure.

## Members

### `dwLength`

The size of the
structure, in bytes. You must set this member before calling
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex).

### `dwMemoryLoad`

A number between 0 and 100 that specifies the approximate percentage of physical memory that is in use (0 indicates no memory use and 100 indicates full memory use).

### `ullTotalPhys`

The amount of actual physical memory, in bytes.

### `ullAvailPhys`

The amount of physical memory currently available, in bytes. This is the amount of physical memory that can be immediately reused without having to write its contents to disk first. It is the sum of the size of the standby, free, and zero lists.

### `ullTotalPageFile`

The current committed memory limit for the system or the current process, whichever is smaller, in bytes. To get the system-wide committed memory limit, call [GetPerformanceInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getperformanceinfo).

### `ullAvailPageFile`

The maximum amount of memory the current process can commit, in bytes. This value is equal to or smaller than the system-wide available commit value. To calculate the system-wide available commit value, call [GetPerformanceInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getperformanceinfo) and subtract the value of **CommitTotal** from the value of **CommitLimit**.

### `ullTotalVirtual`

The size of the user-mode portion of the virtual address space of the calling process, in bytes. This value depends on the type of process, the type of processor, and the configuration of the operating system. For example, this value is approximately 2 GB for most 32-bit processes on an x86 processor and approximately 3 GB for 32-bit processes that are large address aware running on a system with [4-gigabyte tuning](https://learn.microsoft.com/windows/desktop/Memory/4-gigabyte-tuning) enabled.

### `ullAvailVirtual`

The amount of unreserved and uncommitted memory currently in the user-mode portion of the virtual address space of the calling process, in bytes.

### `ullAvailExtendedVirtual`

Reserved. This value is always 0.

## Remarks

**MEMORYSTATUSEX** reflects the state of memory at the time of the call. It also reflects the size of the paging file at that time. The operating system can enlarge the paging file up to the maximum size set by the administrator.

The physical memory sizes returned include the memory from all nodes.

#### Examples

For an example, see the
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function.

## See also

[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))