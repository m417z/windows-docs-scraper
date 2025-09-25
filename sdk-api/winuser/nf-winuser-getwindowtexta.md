# GetWindowTextA function

## Description

Copies the text of the specified window's title bar (if it has one) into a buffer. If the specified window is a control, the text of the control is copied. However, **GetWindowText** cannot retrieve the text of a control in another application.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window or control containing the text.

### `lpString` [out]

Type: **LPTSTR**

The buffer that will receive the text. If the string is as long or longer than the buffer, the string is truncated and terminated with a null character.

### `nMaxCount` [in]

Type: **int**

The maximum number of characters to copy to the buffer, including the null character. If the text exceeds this limit, it is truncated.

## Return value

Type: **int**

If the function succeeds, the return value is the length, in characters, of the copied string, not including the terminating null character. If the window has no title bar or text, if the title bar is empty, or if the window or control handle is invalid, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function cannot retrieve the text of an edit control in another application.

## Remarks

If the target window is owned by the current process, **GetWindowText** causes a [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) message to be sent to the specified window or control. If the target window is owned by another process and has a caption, **GetWindowText** retrieves the window caption text. If the window does not have a caption, the return value is a null string. This behavior is by design. It allows applications to call **GetWindowText** without becoming unresponsive if the process that owns the target window is not responding. However, if the target window is not responding and it belongs to the calling application, **GetWindowText** will cause the calling application to become unresponsive.

To retrieve the text of a control in another process, send a [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) message directly instead of calling **GetWindowText**.

#### Examples

The following example code demonstrates a call to **GetWindowTextA**.

```cpp
hwndCombo = GetDlgItem(hwndDlg, IDD_COMBO);
cTxtLen = GetWindowTextLength(hwndCombo);

// Allocate memory for the string and copy
// the string into the memory.

pszMem = (PSTR) VirtualAlloc((LPVOID) NULL,
    (DWORD) (cTxtLen + 1), MEM_COMMIT,
    PAGE_READWRITE);
GetWindowText(hwndCombo, pszMem,
    cTxtLen + 1);
```

 To see this example in context, see [Sending a Message](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

> [!NOTE]
> The winuser.h header defines GetWindowText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetWindowTextLength](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtextlengtha)

**Reference**

[SetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowtexta)

[WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)