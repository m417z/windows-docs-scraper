## Description

Sets the selected CPU Sets assignment for the specified thread. This assignment overrides the process default assignment, if one is set.

## Parameters

### `Thread`

Specifies the thread on which to set the CPU Set assignment. This handle must have the THREAD\_SET\_LIMITED\_INFORMATION access right. The value returned by [**GetCurrentThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) can also be used.

### `CpuSetIds`

Specifies the list of CPU Set IDs to set as the thread selected CPU set. If this is NULL, the API clears out any assignment, reverting to process default assignment if one is set.

### `CpuSetIdCount`

Specifies the number of IDs in the list passed in the **CpuSetIds** argument. If that value is NULL, this should be 0.

## Return value

If the function succeeds, the return value is nonzero.

This function cannot fail when passed valid parameters.

## Remarks

## See also