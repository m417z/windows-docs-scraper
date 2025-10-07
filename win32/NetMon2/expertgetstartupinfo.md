# ExpertGetStartupInfo function

The **ExpertGetStartupInfo** function retrieves the startup configuration information for the expert.

## Parameters

*hExpertKey* \[in\]

Unique expert identifier. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*pExpertStartupInfo* \[out\]

Pointer to an [EXPERTSTARTUPINFO](https://learn.microsoft.com/windows/win32/netmon2/expertstartupinfo) structure that contains startup information.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is NMERR.

## Remarks

The **ExpertGetStartupInfo** function is used if the expert must determine the startup information that is used.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

