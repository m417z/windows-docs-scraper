# PdhOpenLogW function

## Description

Opens the specified log file for reading or writing.

## Parameters

### `szLogFileName` [in]

**Null**-terminated string that specifies the name of the log file to open. The name can contain an absolute or relative path.

If the *lpdwLogType* parameter is **PDH_LOG_TYPE_SQL**, specify the name of the log file in the form, **SQL:***DataSourceName***!***LogFileName*.

### `dwAccessFlags` [in]

Type of access to use to open the log file. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_LOG_READ_ACCESS** | Open the log file for reading. |
| **PDH_LOG_WRITE_ACCESS** | Open a new log file for writing. |
| **PDH_LOG_UPDATE_ACCESS** | Open an existing log file for writing. |

You can use the bitwise inclusive **OR** operator (|) to combine the access type with one or more of the following creation flags.

| Value | Meaning |
| --- | --- |
| **PDH_LOG_CREATE_NEW** | Creates a new log file with the specified name. |
| **PDH_LOG_CREATE_ALWAYS** | Creates a new log file with the specified name. If the log file already exists, the function removes the existing log file before creating the new file. |
| **PDH_LOG_OPEN_EXISTING** | Opens an existing log file with the specified name. If a log file with the specified name does not exist, this is equal to PDH_LOG_CREATE_NEW. |
| **PDH_LOG_OPEN_ALWAYS** | Opens an existing log file with the specified name or creates a new log file with the specified name. |
| **PDH_LOG_OPT_CIRCULAR** | Creates a circular log file with the specified name. When the file reaches the value of the *dwMaxSize* parameter, data wraps to the beginning of the log file. You can specify this flag only if the *lpdwLogType* parameter is **PDH_LOG_TYPE_BINARY**. |
| **PDH_LOG_USER_STRING** | Used with **PDH_LOG_TYPE_TSV** to write the user caption or log file description indicated by the *szUserString* parameter of [PdhUpdateLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhupdateloga) or **PdhOpenLog**. The user caption or log file description is written as the last column in the first line of the text log. |

### `lpdwLogType` [in]

Type of log file to open. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_LOG_TYPE_UNDEFINED** | Undefined log file format. If specified, PDH determines the log file type. You cannot specify this value if the *dwAccessFlags* parameter is **PDH_LOG_WRITE_ACCESS**. |
| **PDH_LOG_TYPE_CSV** | Text file containing column headers in the first line, and individual data records in each subsequent line. The fields of each data record are comma-delimited.<br><br>The first line also contains information about the format of the file, the PDH version used to create the log file, and the names and paths of each of the counters. |
| **PDH_LOG_TYPE_SQL** | The data source of the log file is an SQL database. |
| **PDH_LOG_TYPE_TSV** | Text file containing column headers in the first line, and individual data records in each subsequent line. The fields of each data record are tab-delimited.<br><br>The first line also contains information about the format of the file, the PDH version used to create the log file, and the names and paths of each of the counters. |
| **PDH_LOG_TYPE_BINARY** | Binary log file format. |

### `hQuery` [in]

Specify a query handle if you are writing query data to a log file. The
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) function returns this handle.

This parameter is ignored and should be **NULL** if you are reading from the log file.

### `dwMaxSize` [in]

Maximum size of the log file, in bytes. Specify the maximum size if you want to limit the file size or if *dwAccessFlags* specifies **PDH_LOG_OPT_CIRCULAR**; otherwise, set to 0.

For circular log files, you must specify a value large enough to hold at least one sample. Sample size depends on data being collected. However, specifying a value of at least one megabyte will cover most samples.

### `szUserCaption` [in]

**Null**-terminated string that specifies the user-defined caption of the log file. A log file caption generally describes the contents of the log file. When an existing log file is opened, the value of this parameter is ignored.

### `phLog` [out]

Handle to the opened log file.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## Remarks

To use this function to write performance data to a log file, you must open a query using
[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya) and add the desired counters to it, before calling this function.

Newer operating systems can read log files that were generated on older operating systems; however, log files that were created on Windows Vista and later operating systems cannot be read on earlier operating systems.

The following rules apply to log files

- READ_ACCESS requires OPEN_EXISTING.

- UPDATE_ACCESS cannot be used with file-based logs. It can only be used with database logs.

- WRITE_ACCESS requires one of CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS.

#### Examples

For an example, see
[Writing Performance Data to a Log File](https://learn.microsoft.com/windows/desktop/PerfCtrs/writing-performance-data-to-a-log-file).

> [!NOTE]
> The pdh.h header defines PdhOpenLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhGetLogFileSize](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetlogfilesize)

[PdhOpenQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenquerya)

[PdhUpdateLog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhupdateloga)

[PdhUpdateLogFileCatalog](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhupdatelogfilecatalog)