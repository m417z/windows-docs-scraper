# PdhSetQueryTimeRange function

## Description

Limits the samples that you can read from a log file to those within the specified time range, inclusively.

## Parameters

### `hQuery` [in]

Handle to the query. The
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

### `pInfo` [in]

A
[PDH_TIME_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_time_info) structure that specifies the time range. Specify the time as local file time. The end time must be greater than the start time. You can specify 0 for the start time and the maximum 64-bit value for the end time if you want to read all records.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The query handle is not valid. |
| **PDH_INVALID_ARGUMENT** | The ending time range value must be greater than the starting time range value. |

## Remarks

When the end of the specified time range or the end of the log file is reached, the
[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata) function will return PDH_NO_MORE_DATA.

## See also

[PdhCollectQueryData](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcollectquerydata)

[PdhGetDataSourceTimeRange](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangea)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)