# PdhVbOpenLog function

The **PdhVbOpenLog** function opens the specified log file for reading and writing. This function calls [**PdhOpenLog**](https://learn.microsoft.com/windows/desktop/api/Pdh/nf-pdh-pdhopenloga).

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbOpenLog( \_ ByVal szLogFileName As LPCTSTR, \_ ByVal dwAccessFlags As DWORD, \_ ByVal lpdwLogType As LPDWORD, \_ ByVal hQuery As PDH\_HQUERY, \_ ByVal dwMaxSize As DWORD, \_ ByVal szUserCaption As LPCSTR, \_ ByRef phLog As PDH\_HLOG \_ ) As DWORD

## Parameters

*szLogFileName* \[in\]

Pointer to a string that specifies the name of the log file to be opened.

If the log file contains SQL data, the format of the name of the log file is **SQL:***DataSourceName***!***LogFileName*. In this case, the value of the *lpdwLogType* parameter is PDH\_LOG\_TYPE\_SQL.

*dwAccessFlags* \[in\]

Type of access to be specified when the log file is opened. This parameter can be one of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|
|

**PDH\_LOG\_READ\_ACCESS**

| A log file is opened for a read operation.<br> |
|

**PDH\_LOG\_WRITE\_ACCESS**

| A new log file is opened for a write operation.<br> |
|

**PDH\_LOG\_UPDATE\_ACCESS**

| An existing log file is opened for a write operation.<br> |

The value selected from the previous table can be combined using the OR operator with one of the following create access flags.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PDH\_LOG\_CREATE\_NEW**

| A new log file with the specified name is created.<br> |
|

**PDH\_LOG\_CREATE\_ALWAYS**

| A new log file with the specified name is created and any existing log file with the same name is erased.<br> |
|

**PDH\_LOG\_OPEN\_EXISTING**

| An existing log file with the specified name is opened. If a log file with the specified name does not exist, this is equal to PDH\_LOG\_CREATE\_NEW.<br> |
|

**PDH\_LOG\_OPEN\_ALWAYS**

| An existing log file with the specified name is opened or a new log file with the specified name is created.<br> |

*lpdwLogType* \[in\]

Pointer to a variable that indicates the type of log file to be opened. This parameter can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
|

**PDH\_LOG\_TYPE\_UNDEFINED**

| Undefined log file format.<br> |
|

**PDH\_LOG\_TYPE\_CSV**

| Text files containing column headers in the first line, and individual data samples in each subsequent line.<br> |
|

**PDH\_LOG\_TYPE\_SQL**

| The data in the log file is in SQL.<br> |
|

**PDH\_LOG\_TYPE\_TSV**

| Same as PDH\_LOG\_TYPE\_CSV.<br> |
|

**PDH\_LOG\_TYPE\_BINARY**

| Binary log file format. Includes circular log files.<br> |
|

**PDH\_LOG\_TYPE\_PERFMON**

| Perfmon log file format.<br> |

*hQuery* \[in\]

Query handle. This handle is returned by the [**PdhVbOpenQuery**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenquery) function.

This parameter can be **NULL** if the log file is to be opened for reading.

*dwMaxSize* \[in\]

Maximum size of the log file, in bytes. This value is used only if the log file is a limited-size or circular log file.

*szUserCaption* \[in\]

Pointer to a string that specifies the user-defined caption of the log file. A log file caption generally describes the contents of the log file. When an existing log file is opened, the value of this parameter is ignored.

*phLog* \[in, ref\]

Pointer to a buffer that receives a handle to the opened log file.

## Return value

If the function succeeds, it returns 0.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a [PDH error code](https://learn.microsoft.com/windows/win32/perfctrs/pdh-error-codes). The following are possible values.

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|
| **PDH\_INSUFFICIENT\_BUFFER** | The requested data is larger than the buffer supplied. Unable to return the requested data.<br> |
| **PDH\_INVALID\_ARGUMENT** | One or more of the string buffers is not the correct size.<br> |
| **PDH\_INVALID\_HANDLE** | The handle is not a valid PDH object.<br> |
| **PDH\_LOG\_FILE\_OPEN\_ERROR** | Unable to open the specified log file.<br> |
| **PDH\_FILE\_NOT\_FOUND** | Unable to find the specified file.<br> |

## Remarks

When using this function to write performance data to a log file, a query must first be opened using [**PdhVbOpenQuery**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenquery).

There must be a currently opened query, and the desired counters must be added to it, before this function is called.

Note that log files in the Perfmon format can only be opened for reading.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhOpenLog**](https://learn.microsoft.com/windows/desktop/api/Pdh/nf-pdh-pdhopenloga)

[**PdhVbGetLogFileSize**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetlogfilesize)

[**PdhVbUpdateLog**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbupdatelog)

