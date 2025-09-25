# SetDlgItemInt function

## Description

Sets the text of a control in a dialog box to the string representation of a specified integer value.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box that contains the control.

### `nIDDlgItem` [in]

Type: **int**

The control to be changed.

### `uValue` [in]

Type: **UINT**

The integer value used to generate the item text.

### `bSigned` [in]

Type: **BOOL**

Indicates whether the *uValue* parameter is signed or unsigned. If this parameter is **TRUE**, *uValue* is signed. If this parameter is **TRUE** and *uValue* is less than zero, a minus sign is placed before the first digit in the string. If this parameter is **FALSE**, *uValue* is unsigned.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To set the new text, this function sends a [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message to the specified control.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemint)

**Reference**

[SetDlgItemText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdlgitemtexta)

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)