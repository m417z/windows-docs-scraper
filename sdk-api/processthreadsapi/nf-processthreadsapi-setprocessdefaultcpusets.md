## Description

Sets the default CPU Sets assignment for threads in the specified process. Threads that are created, which don’t have CPU Sets explicitly set using [**SetThreadSelectedCpuSets**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets), will inherit the sets specified by **SetProcessDefaultCpuSets** automatically.

## Parameters

### `Process`

Specifies the process for which to set the default CPU Sets. This handle must have the PROCESS\_SET\_LIMITED\_INFORMATION access right. The value returned by [**GetCurrentProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can also be specified here.

### `CpuSetIds`

Specifies the list of CPU Set IDs to set as the process default CPU set. If this is NULL, the **SetProcessDefaultCpuSets** clears out any assignment.

### `CpuSetIdCount`

Specifies the number of IDs in the list passed in the **CpuSetIds** argument. If that value is NULL, this should be 0.

## Return value

This function cannot fail when passed valid parameters

## Remarks

## See also