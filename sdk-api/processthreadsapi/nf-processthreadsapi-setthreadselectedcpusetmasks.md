## Description

Sets the selected CPU Sets assignment for the specified thread. This assignment overrides the process default assignment, if one is set.

## Parameters

### `Thread`

Specifies the thread on which to set the CPU Set assignment. [PROCESS_SET_LIMITED_INFORMATION](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights) access right. The value returned by [GetCurrentProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can also be specified here.

### `CpuSetMasks`

Specifies an optional buffer of [GROUP_AFFINITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-group_affinity) structures representing the CPU Sets to set as the thread selected CPU set. If this is NULL, the **SetThreadSelectedCpuSetMasks** function clears out any assignment, reverting to process default assignment if one is set.

### `CpuSetMaskCount`

Specifies the number of **GROUP_AFFINITY** structures in the list passed in the GroupCpuSets argument. If the buffer is NULL, this value must be zero.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero and extended error information can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is analogous to [SetThreadSelectedCpuSets](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets), except that it uses group affinities as opposed to CPU Set IDs to represent a list of CPU sets. This means that the resulting thread selected CPU Set assignment is the set of all CPU sets with a home processor in the provided list of group affinities.

## See also