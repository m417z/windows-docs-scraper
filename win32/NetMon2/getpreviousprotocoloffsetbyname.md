# GetPreviousProtocolOffsetByName function

The **GetPreviousProtocolOffsetByName** function returns the previous instance of a given protocol.

## Parameters

*hFrame* \[in\]

Handle to the frame.

*dwStartOffset* \[in\]

Offset in the frame.

*szProtocolName* \[in\]

Name of the protocol you want to search for.

*pdwPreviousOffset* \[out\]

Pointer to a **DWORD** that contains the offset to the previous protocol (if the function succeeds).

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is NMERR\_PROTOCOL\_NOT\_FOUND.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetPreviousProtocolOffsetByName**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

