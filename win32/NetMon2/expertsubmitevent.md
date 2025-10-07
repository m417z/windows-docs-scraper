# ExpertSubmitEvent function

The **ExpertSubmitEvent** function indicates that an event condition exists and provides a data structure that describes the condition.

## Parameters

*hExpertKey* \[in\]

Unique identifier of the expert. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*pExpertEvent* \[in\]

A pointer to an **NMEVENTDATA** structure that describes the event condition.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value indicates the reason for the failure. If the return value is NMERR\_EXPERT\_TERMINATE, the expert immediately cleans up and returns.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

