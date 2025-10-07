# GetProtocolFromName function

The **GetProtocolFromName** function returns a handle to a protocol of a given name.

## Parameters

*ProtocolName* \[in\]

Protocol name (for example, IP).

## Return value

If the function is successful, the return value is a protocol handle.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetProtocolFromName** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

