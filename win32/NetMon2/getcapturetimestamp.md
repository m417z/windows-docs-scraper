# GetCaptureTimeStamp function

The **GetCaptureTimeStamp** function returns the time and date when the capture started recording frames.

## Parameters

*hCapture* \[in\]

Handle to the capture. For information about obtaining the capture handle, see the Remarks section of this **GetCaptureTimeStamp** topic.

## Return value

If the function is successful, the return value is a pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

The **GetCaptureTimeStamp** function returns the time when the Network Packet Provider (NPP) starts collecting data, not when the expert loads the capture for analysis.

Do not overwrite the data in the **SYSTEMTIME** structure. The data is part of the capture. Trying to modify the data causes an access violation.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetCaptureTimeStamp** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

