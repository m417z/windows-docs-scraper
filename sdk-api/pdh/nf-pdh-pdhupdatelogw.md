# PdhUpdateLogW function

## Description

Collects counter data for the current query and writes the data to the log file.

## Parameters

### `hLog` [in]

Handle of a single log file to update. The
[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga) function returns this handle.

### `szUserString` [in]

Null-terminated string that contains a user-defined comment to add to the data record. The string can not be empty.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_HANDLE** | The log file handle is not valid. |
| **PDH_INVALID_ARGUMENT** | An empty string was passed in the *szUserString* parameter. |

## Remarks

If you are updating a log file from another log file, the comments from the other log file do not migrate.

#### Examples

For an example, see
[Writing Performance Data to a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/writing-performance-data-to-a-log-file).

> [!NOTE]
> The pdh.h header defines PdhUpdateLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhGetLogFileSize](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetlogfilesize)

[PdhOpenLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenloga)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)

[PdhUpdateLogFileCatalog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhupdatelogfilecatalog)