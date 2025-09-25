# GetWindowTextLengthW function

## Description

Retrieves the length, in characters, of the specified window's title bar text (if the window has a title bar). If the specified window is a control, the function retrieves the length of the text within the control. However, **GetWindowTextLength** cannot retrieve the length of the text of an edit control in another application.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window or control.

## Return value

Type: **int**

If the function succeeds, the return value is the length, in characters, of the text. Under certain conditions, this value might be greater than the length of the text (see Remarks).

If the window has no text, the return value is zero.

Function failure is indicated by a return value of zero and a [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) result that is nonzero.

> [!NOTE]
> This function does not clear the most recent error information. To determine success or failure, clear the most recent error information by calling [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with 0, then call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the target window is owned by the current process, **GetWindowTextLength** causes a [WM_GETTEXTLENGTH](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettextlength) message to be sent to the specified window or control.

Under certain conditions, the **GetWindowTextLength** function may return a value that is larger than the actual length of the text. This occurs with certain mixtures of ANSI and Unicode, and is due to the system allowing for the possible existence of double-byte character set (DBCS) characters within the text. The return value, however, will always be at least as large as the actual length of the text; you can thus always use it to guide buffer allocation. This behavior can occur when an application uses both ANSI functions and common dialogs, which use Unicode. It can also occur when an application uses the ANSI version of **GetWindowTextLength** with a window whose window procedure is Unicode, or the Unicode version of **GetWindowTextLength** with a window whose window procedure is ANSI. For more information on ANSI and ANSI functions, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/desktop/Intl/conventions-for-function-prototypes).

To obtain the exact length of the text, use the [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext), [LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext), or [CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext) messages, or the [GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta) function.

> [!NOTE]
> The winuser.h header defines GetWindowTextLength as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext)

**Conceptual**

[GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta)

[LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext)

**Other Resources**

**Reference**

[SetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowtexta)

[WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext)

[WM_GETTEXTLENGTH](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettextlength)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)