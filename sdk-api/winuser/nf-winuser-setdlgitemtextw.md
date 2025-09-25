# SetDlgItemTextW function

## Description

Sets the title or text of a control in a dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box that contains the control.

### `nIDDlgItem` [in]

Type: **int**

The control with a title or text to be set.

### `lpString` [in]

Type: **LPCTSTR**

The text to be copied to the control.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetDlgItemText** function sends a [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message to the specified control.

#### Examples

For an example, see [Using List Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-list-boxes).

> [!NOTE]
> The winuser.h header defines SetDlgItemText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemint)

[GetDlgItemText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemtexta)

**Reference**

[SetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdlgitemint)

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)