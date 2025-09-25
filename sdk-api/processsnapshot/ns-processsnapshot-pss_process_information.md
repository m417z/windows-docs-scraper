# PSS_PROCESS_INFORMATION structure

## Description

Holds process information returned by [PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot).

## Members

### `ExitStatus`

The exit code of the process. If the process has not exited, this is set to **STILL_ACTIVE** (259).

### `PebBaseAddress`

The address to the process environment block (PEB). Reserved for use by the operating system.

### `AffinityMask`

The affinity mask of the process.

### `BasePriority`

The base priority level of the process.

### `ProcessId`

The process ID.

### `ParentProcessId`

The parent process ID.

### `Flags`

Flags about the process. For more information, see [PSS_PROCESS_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_process_flags).

### `CreateTime`

The time the process was created. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `ExitTime`

If the process exited, the time of the exit. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `KernelTime`

The amount of time the process spent executing in kernel-mode. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `UserTime`

The amount of time the process spent executing in user-mode. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `PriorityClass`

The priority class.

### `PeakVirtualSize`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `VirtualSize`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `PageFaultCount`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `PeakWorkingSetSize`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `WorkingSetSize`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `QuotaPeakPagedPoolUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `QuotaPagedPoolUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `QuotaPeakNonPagedPoolUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `QuotaNonPagedPoolUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `PagefileUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `PeakPagefileUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `PrivateUsage`

A memory usage counter. See the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function for more information.

### `ExecuteFlags`

Reserved for use by the operating system.

### `ImageFileName`

The full path to the process executable. If the path exceeds the allocated buffer size, it is truncated.

## Remarks

[PssQuerySnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssquerysnapshot) returns a **PSS_PROCESS_INFORMATION** structure when the [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class) member that the caller provides it is **PSS_QUERY_PROCESS_INFORMATION**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)