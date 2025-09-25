## Description

Retrieves the list of CPU Sets in the process default set that was set by [**SetProcessDefaultCpuSets**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusets). If no default CPU Sets are set for a given process, then the **RequiredIdCount** is set to 0 and the function succeeds.

## Parameters

### `Process`

Specifies a process handle for the process to query. This handle must have the PROCESS\_QUERY\_LIMITED\_INFORMATION access right. The value returned by [**GetCurrentProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) can also be specified here.

### `CpuSetIds`

Specifies an optional buffer to retrieve the list of CPU Set identifiers.

### `CpuSetIdCount`

Specifies the capacity of the buffer specified in **CpuSetIds**. If the buffer is NULL, this must be 0.

### `RequiredIdCount`

Specifies the required capacity of the buffer to hold the entire list of process default CPU Sets. On successful return, this specifies the number of IDs filled into the buffer.

## Return value

This API returns TRUE on success. If the buffer is not large enough the API returns FALSE, and the **GetLastError** value is ERROR\_INSUFFICIENT\_BUFFER. This API cannot fail when passed valid parameters and the return buffer is large enough.

## Remarks

## See also