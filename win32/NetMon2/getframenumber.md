# GetFrameNumber function

The **GetFrameNumber** function returns the number of a frame.

## Parameters

*hFrame* \[in\]

Handle to the frame.

## Return value

If the function is successful, the return value is a zero-based frame number.

If the function is not successful, the return value is minus one (-1).

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameNumber** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

