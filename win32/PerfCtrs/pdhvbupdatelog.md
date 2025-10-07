# PdhVbUpdateLog function

The **PdhVbUpdateLog** function function updates the current query and writes new data to the log file. This function calls [**PdhUpdateLog**](https://learn.microsoft.com/windows/desktop/api/Pdh/nf-pdh-pdhupdateloga).

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbUpdateLog( \_ ByVal hLog As PDH\_HLOG, \_ ByVal szUserString As LPCTSTR \_ )

## Parameters

*hLog* \[in\]

Handle to the log file to be updated. This handle is returned by the [**PdhVbOpenLog**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenlog) function.

*szUserString* \[in\]

Pointer to a string that specifies the data to be added to the log file. This is generally used for comments within the log file.

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

There must be a currently opened query, and the desired counters must be added to it before this function is called.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhUpdateLog**](https://learn.microsoft.com/windows/desktop/api/Pdh/nf-pdh-pdhupdateloga)

[**PdhVbGetLogFileSize**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetlogfilesize)

[**PdhVbOpenLog**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenlog)

