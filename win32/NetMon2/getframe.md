# GetFrame function

The **GetFrame** function returns a handle to a given frame within a capture.

## Parameters

*hCapture* \[in\]

Handle to a capture. To obtain the capture handle, call the [GetFrameCaptureHandle](https://learn.microsoft.com/windows/win32/netmon2/getframecapturehandle) function.

*FrameNumber* \[in\]

Number (zero-based) of the frame. The number of the first frame in a capture is zero.

## Return value

If the function is successful, the return value is a handle to the frame.

If the function is unsuccessful (that is, if *hCapture* is invalid, or the frame number is out of range), the return value is **NULL**.

## Remarks

Use the **GetFrame** function to obtain the frame handle needed when locating instances of a property. The functions used to locate property instances are [FindPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstance) which locates the first instance, and [FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart) which locates the next instance.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrame** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[FindPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstance)

[FindPropertyInstanceRestart](https://learn.microsoft.com/windows/win32/netmon2/findpropertyinstancerestart)

