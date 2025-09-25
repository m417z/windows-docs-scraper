# GetDlgItemTextA function

## Description

Retrieves the title or text associated with a control in a dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box that contains the control.

### `nIDDlgItem` [in]

Type: **int**

The identifier of the control whose title or text is to be retrieved.

### `lpString` [out]

Type: **LPTSTR**

The buffer to receive the title or text.

### `cchMax` [in]

Type: **int**

The maximum length, in characters, of the string to be copied to the buffer pointed to by *lpString*. If the length of the string, including the null character, exceeds the limit, the string is truncated.

## Return value

Type: **UINT**

If the function succeeds, the return value specifies the number of characters copied to the buffer, not including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the string is as long or longer than the buffer, the buffer will contain the truncated string with a terminating null character.

The **GetDlgItemText** function sends a [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) message to the control.

#### Examples

For an example, see [Creating a Modal Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

> [!NOTE]
> The winuser.h header defines GetDlgItemText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemint)

**Reference**

[SetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdlgitemint)

[SetDlgItemText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdlgitemtexta)

[WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext)