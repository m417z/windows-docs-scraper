# PdhVbGetOneCounterPath function

The **PdhVbGetOneCounterPath** function displays a dialog box that lets the user browse the available performance counters and select one counter. The counter selected is returned in the *PathString* variable. The *PathString* variable must be dimensioned and initialized before this function is called, and the dimensioned size must be indicated by the *PathLength* variable.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbGetOneCounterPath( \_ ByVal PathString As String, \_ ByVal PathLength As Long, \_ ByVal DetailLevel As Long, \_ ByVal CaptionString As String \_ ) As Long

## Parameters

*PathString*

Initialized string variable used to receive the counter path selected by the user.

*PathLength*

Length of the initialized PathString.

*DetailLevel*

Types of counters to be displayed in the dialog box. This parameter can be one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| **PERF\_DETAIL\_ADVANCED** | Counters that the advanced user is likely to understand, in addition to the novice-user counters.<br> |
| **PERF\_DETAIL\_EXPERT** | Counters that the expert user and software developer is likely to understand, in addition to the counters for the novice and advanced users.<br> |
| **PERF\_DETAIL\_NOVICE** | Only counters that the novice user is likely to understand.<br> |
| **PERF\_DETAIL\_WIZARD** | All counters in the system.<br> |

*CaptionString*

String variable that contains the text that will be displayed in the caption bar of the dialog box.

## Return value

The function returns the number of characters written to the *PathString* buffer.

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

[**PdhVbGetCounterPathFromList**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetcounterpathfromlist)

