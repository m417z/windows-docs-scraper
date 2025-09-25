# SetWindowTextA function

## Description

Changes the text of the specified window's title bar (if it has one). If the specified window is a control, the text of the control is changed. However, **SetWindowText** cannot change the text of a control in another application.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window or control whose text is to be changed.

### `lpString` [in, optional]

Type: **LPCTSTR**

The new title or control text.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the target window is owned by the current process, **SetWindowText** causes a [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message to be sent to the specified window or control. If the control is a list box control created with the **WS_CAPTION** style, however, **SetWindowText** sets the text for the control, not for the list box entries.

To set the text of a control in another process, send the [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message directly instead of calling **SetWindowText**.

The **SetWindowText** function does not expand tab characters (ASCII code 0x09). Tab characters are displayed as vertical bar (|) characters.

#### Examples

 For an example, see [Sending a Message](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

> [!NOTE]
> The winuser.h header defines SetWindowText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta)

**Reference**

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)