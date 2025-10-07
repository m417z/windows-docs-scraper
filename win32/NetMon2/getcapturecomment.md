# GetCaptureComment function

The **GetCaptureComment** function returns a pointer to the comment of a capture.

## Parameters

*hCapture* \[in\]

A handle to the capture. For more information about obtaining the capture handle, see the Remarks section.

## Return value

If the function is successful (that is, if the capture contains a comment), the return value is a pointer to the comment string.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

Do not alter the returned comment string which is the actual comment string that is in the loaded capture. Any changes can corrupt the capture. Attempts to modify the string result in an access violation.

The handle of the capture can be obtained in several ways, depending if the call is made by an expert or parser. For experts, the handle is specified in the **hCapture** member of the [EXPERTSTARTUPINFO](https://learn.microsoft.com/windows/win32/netmon2/expertstartupinfo) structure. For parsers, the capture handle can be obtained by calling the [GetFrameCaptureHandle](https://learn.microsoft.com/windows/win32/netmon2/getframecapturehandle) function.

To retrieve the comment of a capture from its capture file, call the [GetCaptureCommentFromFilename](https://learn.microsoft.com/windows/win32/netmon2/getcapturecommentfromfilename) function.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetCaptureComment** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[EXPERTSTARTUPINFO](https://learn.microsoft.com/windows/win32/netmon2/expertstartupinfo)

[GetCaptureCommentFromFilename](https://learn.microsoft.com/windows/win32/netmon2/getcapturecommentfromfilename)

[GetFrameCaptureHandle](https://learn.microsoft.com/windows/win32/netmon2/getframecapturehandle)

