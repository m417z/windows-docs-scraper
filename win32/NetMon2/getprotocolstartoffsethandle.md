# GetProtocolStartOffsetHandle function

The **GetProtocolStartOffsetHandle** function returns the frame offset of a given protocol.

## Parameters

*hFrame* \[in\]

Handle to a frame.

*hProtocol* \[in\]

Handle to a protocol.

## Return value

If the function is successful, the return value is the offset of the frame measured in bytes.

If the function is unsuccessful, the return value is one (1).

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetProtocolStartOffsetHandle** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

