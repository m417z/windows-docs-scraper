# GetEnabledProtocols function

The **GetEnabledProtocols** function returns a table of all protocols that are marked Enabled.

## Parameters

*hCapture* \[in\]

Handle to the capture.

## Return value

If the function is successful, the return value is a pointer to a [PROTOCOLTABLE](https://learn.microsoft.com/windows/win32/netmon2/protocoltable) structure that lists all the enabled protocols in the capture.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetEnabledProtocols** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[PROTOCOLTABLE](https://learn.microsoft.com/windows/win32/netmon2/protocoltable)

