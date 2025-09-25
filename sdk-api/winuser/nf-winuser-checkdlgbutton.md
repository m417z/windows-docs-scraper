# CheckDlgButton function

## Description

Changes the check state of a button control.

## Parameters

### `hDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the button.

### `nIDButton` [in]

Type: **int**

The identifier of the button to modify.

### `uCheck` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The check state of the button. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BST_CHECKED** | Sets the button state to checked. |
| **BST_INDETERMINATE** | Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the [BS_3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) or [BS_AUTO3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) style. |
| **BST_UNCHECKED** | Sets the button state to cleared |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CheckDlgButton** function sends a
[BM_SETCHECK](https://learn.microsoft.com/windows/desktop/Controls/bm-setcheck) message to the specified button control in the specified dialog box.

#### Examples

For an example, see **Creating a Modeless Dialog Box** in [Using Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

[CheckRadioButton](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-checkradiobutton)

[IsDlgButtonChecked](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdlgbuttonchecked)

**Reference**