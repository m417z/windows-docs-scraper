# PdhGetLogFileSize function

## Description

Returns the size of the specified log file.

## Parameters

### `hLog` [in]

Handle to the log file. The
[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga) or [PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea) function returns this handle.

### `llSize` [out]

Size of the log file, in bytes.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_LOG_FILE_OPEN_ERROR** | An error occurred when trying to open the log file. |
| **PDH_INVALID_HANDLE** | The handle is not valid. |

## Remarks

If the log file handle points to multiple bound log files, the size is the sum of all the log files. If the log file is a SQL log file, the *llSize* parameter is the number of records in the log file.

## See also

[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga)