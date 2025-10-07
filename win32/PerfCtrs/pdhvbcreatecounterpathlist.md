# PdhVbCreateCounterPathList function

The **PdhVbCreateCounterPathList** function displays the performance counter browsing dialog box, which lets the user select several performance counters. Each selected counter path must then be read using the [**PdhVbGetCounterPathFromList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathfromlist) function.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbCreateCounterPathList( \_ ByVal DetailLevel As Long, \_ ByVal CaptionString As String \_ ) As Long

## Parameters

*DetailLevel*

Types of counters to be displayed in the dialog box. Use one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PERF\_DETAIL\_ADVANCED**

| Counters that the advanced user is likely to understand, in addition to the novice-user counters.<br> |
|

**PERF\_DETAIL\_EXPERT**

| Counters that the expert user and software developer is likely to understand, in addition to the counters for the novice and advanced users.<br> |
|

**PERF\_DETAIL\_NOVICE**

| Only counters that the novice user is likely to understand.<br> |
|

**PERF\_DETAIL\_WIZARD**

| All counters in the system.<br> |

*CaptionString*

String variable that contains the text that will be displayed in the caption bar of the dialog box.

## Return value

The function returns the number of counter paths that the user selected.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhVbGetCounterPathElements**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathelements)

[**PdhVbGetCounterPathFromList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathfromlist)

[**PdhVbGetOneCounterPath**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetonecounterpath)

