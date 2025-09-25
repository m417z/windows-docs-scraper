## Description

Retrieves the list of CPU Sets in the process default set that was set by [SetProcessDefaultCpuSetMasks](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusetmasks) or [SetProcessDefaultCpuSets](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusets).

## Parameters

### `Process`

Specifies a process handle for the process to query. This handle must have the [PROCESS_QUERY_LIMITED_INFORMATION](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights) access right. The value returned by [GetCurrentProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can also be specified here.

### `CpuSetMasks`

Specifies an optional buffer to retrieve a list of [GROUP_AFFINITY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-group_affinity) structures representing the process default CPU Sets.

### `CpuSetMaskCount`

Specifies the size of the *CpuSetMasks* array, in elements.

### `RequiredMaskCount`

On successful return, specifies the number of affinity structures written to the array. If the *CpuSetMasks* array is too small, the function fails with **ERROR_INSUFFICIENT_BUFFER** and sets the *RequiredMaskCount* parameter to the number of elements required. The number of required elements is always less than or equal to the maximum group count returned by [GetMaximumProcessorGroupCount](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getmaximumprocessorgroupcount).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero and extended error information can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the array supplied is too small, the error value is **ERROR_INSUFFICIENT_BUFFER** and the *RequiredMaskCount* is set to the number of elements required.

## Remarks

If no default CPU Sets are set for a given process, then the *RequiredMaskCount* parameter is set to 0 and the function succeeds.

This function is analogous to [GetProcessDefaultCpuSets](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessdefaultcpusets), except that it uses group affinities as opposed to CPU Set IDs to represent a list of CPU sets. This means that the process default CPU Sets are mapped to their home processors, and those processors are retrieved in the resulting list of group affinities.

## See also