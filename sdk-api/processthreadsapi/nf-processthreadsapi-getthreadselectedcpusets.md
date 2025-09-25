## Description

Returns the explicit CPU Set assignment of the specified thread, if any assignment was set using the [**SetThreadSelectedCpuSets**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets) API. If no explicit assignment is set, **RequiredIdCount** is set to 0 and the function returns TRUE.

## Parameters

### `Thread`

Specifies the thread for which to query the selected CPU Sets. This handle must have the THREAD\_QUERY\_LIMITED\_INFORMATION access right. The value returned by [**GetCurrentThread**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) can also be specified here.

### `CpuSetIds`

Specifies an optional buffer to retrieve the list of CPU Set identifiers.

### `CpuSetIdCount`

Specifies the capacity of the buffer specified in **CpuSetIds**. If the buffer is NULL, this must be 0.

### `RequiredIdCount`

Specifies the required capacity of the buffer to hold the entire list of thread selected CPU Sets. On successful return, this specifies the number of IDs filled into the buffer.

## Return value

This API returns TRUE on success. If the buffer is not large enough, the **GetLastError** value is ERROR\_INSUFFICIENT\_BUFFER. This API cannot fail when passed valid parameters and the return buffer is large enough.

## Remarks

## See also