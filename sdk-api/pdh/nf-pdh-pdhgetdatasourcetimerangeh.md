# PdhGetDataSourceTimeRangeH function

## Description

Determines the time range, number of entries and, if applicable, the size of the buffer containing the performance data from the specified input source.

This function is identical to
the [PdhGetDataSourceTimeRange](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangea) function, except that it supports the use of handles to data sources.

## Parameters

### `hDataSource` [in]

Handle to a data source returned by the
[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea) function.

### `pdwNumEntries` [out]

Number of structures in the *pInfo* buffer. This function collects information for only one time range, so the value is typically 1, or zero if an error occurred.

### `pInfo` [out]

A
[PDH_TIME_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_time_info) structure that receives the time range. The information spans all bound log files.

### `pdwBufferSize` [in]

Size of the [PDH_TIME_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_time_info) structure, in bytes.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |
| **PDH_DATA_SOURCE_IS_REAL_TIME** | The current data source is a real-time data source. |

## See also

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)