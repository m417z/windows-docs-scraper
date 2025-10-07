# PdhVbGetCounterPathElements function

The **PdhVbGetCounterPathElements** function parses a fully qualified performance counter path string into its individual elements. Each of the string variables must be the same size (*BufferSize*) and dimensioned and initialized before it is used in this function.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbGetCounterPathElements( \_ ByVal PathString As String, \_ ByVal MachineName As String, \_ ByVal ObjectName As String, \_ ByVal InstanceName As String, \_ ByVal ParentInstance As String, \_ ByVal CounterName As String, \_ ByVal BufferSize As Long \_ ) As Long

## Parameters

*PathString*

Counter path string that is to be broken up into its individual elements.

*MachineName*

String to receive the computer name.

*ObjectName*

String to receive the object name.

*InstanceName*

String to receive the instance name, if used.

*ParentInstance*

String to receive the parent instance, if used.

*CounterName*

String to receive the counter name.

*BufferSize*

Maximum size of each string variable used as a parameter to this function call.

## Return value

If the function succeeds, it returns a **Long** integer equal to ERROR\_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a [PDH error code](https://learn.microsoft.com/windows/win32/perfctrs/pdh-error-codes). The following are possible values.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **PDH\_INVALID\_ARGUMENT** | One or more of the string buffers is not the correct size.<br> |
| **PDH\_MORE\_DATA** | One or more of the counter path elements is too large for the return buffer length.<br> |
| **PDH\_MEMORY\_ALLOCATION\_FAILURE** | A temporary memory buffer could not be allocated.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhVbCreateCounterPathList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbcreatecounterpathlist)

[**PdhVbGetCounterPathFromList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathfromlist)

[**PdhVbGetOneCounterPath**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetonecounterpath)

