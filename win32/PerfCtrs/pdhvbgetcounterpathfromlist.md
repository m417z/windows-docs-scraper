# PdhVbGetCounterPathFromList function

The **PdhVbGetCounterPathFromList** function copies the counter path referenced by the *Index* parameter from a counter path list created by the user from the most recent call to the [**PdhVbCreateCounterPathList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbcreatecounterpathlist) function.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbGetCounterPathFromList( \_ ByVal Index As Long, \_ ByVal Buffer As String, \_ ByVal BufferLength As Long \_ ) As Long

## Parameters

*Index*

Index of the counter path to retrieve. This must be a value that is greater than or equal to 1, and less than or equal to the value returned by the [**PdhVbCreateCounterPathList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbcreatecounterpathlist) function.

*Buffer*

Dimensioned and initialized string that will receive the counter path that corresponds to the value of the Index parameter.

*BufferLength*

Maximum number of characters that will fit in the string referenced by Buffer.

## Return value

The function returns the number of characters copied to Buffer.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhVbCreateCounterPathList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbcreatecounterpathlist)

[**PdhVbGetCounterPathElements**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathelements)

[**PdhVbGetOneCounterPath**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetonecounterpath)

