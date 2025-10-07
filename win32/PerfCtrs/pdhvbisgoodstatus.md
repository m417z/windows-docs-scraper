# PdhVbIsGoodStatus function

The **PdhVbIsGoodStatus** function tests a status value to determine if it is a success or failure code. If the status value is a successful one, then the return value will be nonzero. If it is a failure status code, the return value will be zero.

> [!IMPORTANT]
> The function that this topic describes may be altered or unavailable in the future. Instead, Microsoft recommends that you use the functions described in [Performance Counters Functions](https://learn.microsoft.com/windows/win32/perfctrs/performance-counters-functions).

Function PdhVbIsGoodStatus( \_ ByVal StatusValue As Long \_ ) As Long

## Parameters

*StatusValue*

Status value returned by another PDH function that is to be tested.

## Return value

The function returns zero if the status code is a failure status code. It returns nonzero if the status code is a success status code.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Library<br> | Pdh.lib |
| DLL<br> | Pdh.dll |

## See also

[**PdhVbGetDoubleCounterValue**](https://learn.microsoft.com/windows/win32/perfctrs/pdhvbgetdoublecountervalue)

