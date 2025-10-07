# PdhVbOpenQuery function

The **PdhVbOpenQuery** function creates and initializes a unique query structure that is used to manage the collection of performance data.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbOpenQuery( \_ ByVal QueryHandle As Long \_ ) As Long

## Parameters

*QueryHandle*

Variable that is cleared (equals 0) before the function is called and, if the function is successful, contains the unique ID of the query that is created and opened. This handle is used in the subsequent calls to other PDH functions to identify the query.

## Return value

If the function succeeds, it returns a **Long** integer equal to ERROR\_SUCCESS and a new handle in the *QueryHandle* variable.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a [PDH error code](https://learn.microsoft.com/windows/win32/perfctrs/pdh-error-codes). The following are possible values.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------|
| **PDH\_INVALID\_ARGUMENT** | The argument is invalid or incorrect.<br> |
| **PDH\_MEMORY\_ALLOCATION\_FAILURE** | A temporary memory buffer could not be allocated.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhCloseQuery**](https://learn.microsoft.com/windows/desktop/api/Pdh/nf-pdh-pdhclosequery)

