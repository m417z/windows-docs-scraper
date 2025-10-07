# ModifyFrame function

The **ModifyFrame** function alters an existing frame with new data.

## Parameters

*hCapture* \[in\]

Handle to the capture. For information about obtaining the capture handle, see the Remarks section of this **ModifyFrame** topic.

*FrameNumber* \[in\]

Frame index number.

*FrameData* \[in\]

Pointer to an array of bytes that contain the new frame data.

*FrameLength* \[in\]

Length of the new data, in bytes.

*TimeStamp* \[out\]

Time stamp indicating when the frame was modified.

## Return value

If the function is successful, the return value is a handle to a new frame.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

If the call is successful, the **ModifyFrame** function destroys the original frame.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **ModifyFrame** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

