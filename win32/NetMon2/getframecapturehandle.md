# GetFrameCaptureHandle function

The **GetFrameCaptureHandle** function returns a handle to the capture based on a given frame.

## Parameters

*hFrame* \[in\]

Handle to a frame.

## Return value

If the function is successful, the return value is a handle to the capture.

If the function is unsuccessful, the return value is 0.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameCaptureHandle** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

