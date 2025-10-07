# GetFrameMacHeaderLength function

The **GetFrameMacHeaderLength** function returns the length, in bytes, of the MAC header of the frame.

## Parameters

*hFrame* \[in\]

Handle to the frame.

## Return value

If the function is successful, the return value is the length in bytes of the MAC header.

If the function is not successful, or an unknown MAC type is encountered, the return value is zero.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameMacHeaderLength** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

