# PdhVbAddCounter function

The **PdhVbAddCounter** function creates a counter entry in the specified query object, and returns a handle to that counter upon successful completion.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbAddCounter( \_ ByVal QueryHandle As Long, \_ ByVal CounterPath As String, \_ ByVal CounterHandle As Long \_ ) As Long

## Parameters

*QueryHandle*

ID of the query to which this counter is to be assigned. This value is returned by the [**PdhVbOpenQuery**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenquery) function.

*CounterPath*

Text string that specifies the name of the counter path to add to the query. The contents of this string must be a valid counter path, as obtained from the counter browser or other source.

*CounterHandle*

Unique reference that identifies this counter in the query. This variable must be initialized to zero before the function is called. It contains a valid value on return only if the function completes successfully.

## Return value

If the function succeeds, it returns a **Long** integer equal to ERROR\_SUCCESS and a new handle in the *CounterHandle* variable.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a [PDH error code](https://learn.microsoft.com/windows/win32/perfctrs/pdh-error-codes). The following are possible values.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| **PDH\_INVALID\_ARGUMENT** | One or more of the arguments is invalid or incorrect.<br> |
| **PDH\_MEMORY\_ALLOCATION\_FAILURE** | A memory buffer could not be allocated.<br> |
| **PDH\_INVALID\_HANDLE** | The query handle is not valid.<br> |
| **PDH\_CSTATUS\_NO\_COUNTER** | The specified counter was not found.<br> |
| **PDH\_CSTATUS\_NO\_OBJECT** | The specified object could not be found.<br> |
| **PDH\_CSTATUS\_NO\_MACHINE** | A computer entry could not be created.<br> |
| **PDH\_CSTATUS\_BAD\_COUNTERNAME** | An empty counter name path string was passed in.<br> |
| **PDH\_FUNCTION\_NOT\_FOUND** | The calculation function for this counter could not be determined.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhVbOpenQuery**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbopenquery)

