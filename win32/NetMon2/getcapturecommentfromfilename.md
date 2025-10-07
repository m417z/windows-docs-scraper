# GetCaptureCommentFromFilename function

The **GetCaptureCommentFromFilename** function extracts the capture comment from a [*capture file*](https://learn.microsoft.com/windows/win32/netmon2/c).

## Parameters

*lpFilename* \[in\]

Pointer to the name of the capture file.

*lpComment* \[in\]

Pointer to a pre-allocated string for the comment.

*BufferSize* \[in\]

Size of the string.

## Return value

If the function is successful (that is, if the comment is found and copied, or there is no comment in the capture file), the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|-------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| **NMERR\_FILE\_READ\_ERROR** | The capture comment cannot be read.<br> |
| **NMERR\_INVALID\_FILE\_FORMAT** | The Comment frame is not a valid file format.<br> |
| **NMERR\_FILE\_NOT\_FOUND** | The file specified by the *lpFilename* parameter cannot be found.<br> |
| **NMERR\_INVALID\_PARAMETER** | One of the parameters is specified incorrectly.<br> |

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetCaptureCommentFromFilename** function.

To retrieve the comment of a real-time capture, call the [GetCaptureComment](https://learn.microsoft.com/windows/win32/netmon2/getcapturecomment) function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[GetCaptureComment](https://learn.microsoft.com/windows/win32/netmon2/getcapturecomment)

