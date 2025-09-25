# InternalGetWindowText function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Copies the text of the specified window's title bar (if it has one) into a buffer.

This function is similar to the [GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta) function.
However, it obtains the window text directly from the window structure
associated with the specified window's handle and then always provides the text as a
Unicode string. This is unlike **GetWindowText** which obtains the
text by sending the window a [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) message. If the
specified window is a control, the text of the control is obtained.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window or control containing the text.

### `pString` [out]

Type: **LPWSTR**

The buffer that is to receive the text.
If the string is as long or longer than the buffer, the string is truncated and terminated with a null character.

### `cchMaxCount` [in]

Type: **int**

The maximum number of characters to be copied to the buffer, including the null character. If the text exceeds this limit, it is truncated.

## Return value

Type: **int**

If the function succeeds, the return value is the length, in characters, of the copied string, not including the terminating null character.

If the window has no title bar or text, if the title bar is empty, or if the window or control handle is invalid, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function was not included in the SDK headers and libraries until Windows XP with Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

**Conceptual**

[GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta)

[GetWindowTextLength](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtextlengtha)

**Reference**

[SetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowtexta)

[Using Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues)

[WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)