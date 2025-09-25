## Description

Sets the default CPU Sets assignment for threads in the specified process.

## Parameters

### `Process`

Specifies the process for which to set the default CPU Sets. This handle must have the [PROCESS_SET_LIMITED_INFORMATION](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights) access right. The value returned by [GetCurrentProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can also be specified here.

### `CpuSetMasks`

Specifies an optional buffer of [GROUP_AFFINITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-group_affinity) structures representing the CPU Sets to set as the process default CPU set. If this is NULL, the **SetProcessDefaultCpuSetMasks** function clears out any assignment.

### `CpuSetMaskCount`

Specifies the size of the *CpuSetMasks* array, in elements. If the buffer is NULL, this value must be zero.

## Return value

This function cannot fail when passed valid parameters.

## Remarks

Threads belonging to this process which don’t have CPU Sets explicitly set using [SetThreadSelectedCpuSetMasks](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusetmasks) or [SetThreadSelectedCpuSets](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets), will inherit the sets specified by **SetProcessDefaultCpuSetMasks** automatically.

This function is analogous to [SetProcessDefaultCpuSets](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusets), except that it uses group affinities as opposed to CPU Set IDs to represent a list of CPU sets. This means that the resulting process default CPU Set assignment is the set of all CPU sets with a home processor in the provided list of group affinities.

## See also