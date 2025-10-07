# GetCaptureTotalFrames function

The **GetCaptureTotalFrames** function returns the total number of frames in the capture.

## Parameters

*hCapture* \[in\]

Handle to the capture. For information about obtaining the capture handle, see the Remarks section of this **GetCaptureTotalFrames** topic.

## Return value

If the function is successful, the return value is the total number of frames in the capture.

If the function is unsuccessful, the return value is 0.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetCaptureTotalFrames** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

