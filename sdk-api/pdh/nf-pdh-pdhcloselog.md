# PdhCloseLog function

## Description

Closes the specified log file.

## Parameters

### `hLog` [in]

Handle to the log file to be closed. This handle is returned by the
[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga) function.

### `dwFlags` [in]

You can specify the following flag.

| Value | Meaning |
| --- | --- |
| **PDH_FLAGS_CLOSE_QUERY** | Closes the query associated with the specified log file handle. See the *hQuery* parameter of [PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga). |

## Return value

If the function succeeds, it returns ERROR_SUCCESS and closes and deletes the query.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following is a possible value.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The log file handle is not valid. |

## See also

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)

[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga)