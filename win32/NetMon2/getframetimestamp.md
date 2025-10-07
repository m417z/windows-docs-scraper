# GetFrameTimeStamp function

The **GetFrameTimeStamp** function returns the time stamp of a given frame.

## Parameters

*hFrame* \[in\]

Handle to the frame.

## Return value

If the function is successful, the return value is the time stamp of the frame in microseconds.

If the function is unsuccessful, the return value is minus one (-1).

## Remarks

The **GetFrameTimeStamp** function returns a time stamp that shows the elapsed time between the start of the capture process, and the recording of the frame.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameTimeStamp** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

