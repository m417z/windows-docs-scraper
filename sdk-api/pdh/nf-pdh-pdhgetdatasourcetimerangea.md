# PdhGetDataSourceTimeRangeA function

## Description

Determines the time range, number of entries and, if applicable, the size of the buffer containing the performance data from the specified input source.

To use handles to data sources, use the
[PdhGetDataSourceTimeRangeH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangeh) function.

## Parameters

### `szDataSource` [in]

Null-terminated string that specifies the name of a log file from which the time range information is retrieved.

### `pdwNumEntries` [out]

Number of structures in the *pInfo* buffer. This function collects information for only one time range, so the value is typically 1, or zero if an error occurred.

### `pInfo` [out]

A
[PDH_TIME_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_time_info) structure that receives the time range.

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

[PdhGetDataSourceTimeRangeH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangeh)

[PdhSetQueryTimeRange](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhsetquerytimerange)

## Remarks

> [!NOTE]
> The pdh.h header defines PdhGetDataSourceTimeRange as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).