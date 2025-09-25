# PdhUpdateLogFileCatalog function

## Description

Synchronizes the information in the log file catalog with the performance data in the log file.

**Note** This function is obsolete.

## Parameters

### `hLog` [in]

Handle to the log file containing the file catalog to update. The
[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga) function.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_NOT_IMPLEMENTED** | A handle to a CSV or TSV log file was specified. These log file types do not have catalogs. |
| **PDH_UNKNOWN_LOG_FORMAT** | A handle to a log file with an unknown format was specified. |
| **PDH_INVALID_HANDLE** | The handle is not valid. |

## Remarks

The log file catalog serves as an index to the performance data records in the log file, providing for faster searches for individual records in the file.

Catalogs should be updated when the data collection process is complete and the log file has been closed. The catalog can be updated during data collection, but doing this may disrupt the process of logging the performance data because updating the catalogs can be time consuming.

Perfmon, CSV, and TSV log files do not have catalogs. Specifying a handle to these log file types will result in a return value of PDH_NOT_IMPLEMENTED.

## See also

[PdhGetLogFileSize](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetlogfilesize)

[PdhUpdateLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhupdateloga)