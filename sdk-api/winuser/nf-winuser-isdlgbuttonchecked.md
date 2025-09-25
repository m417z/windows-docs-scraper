# IsDlgButtonChecked function

## Description

The **IsDlgButtonChecked** function determines whether a button control is checked or whether a three-state button control is checked, unchecked, or indeterminate.

## Parameters

### `hDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the button control.

### `nIDButton` [in]

Type: **int**

The identifier of the button control.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value from a button created with the [BS_AUTOCHECKBOX](https://learn.microsoft.com/windows/desktop/Controls/button-styles), [BS_AUTORADIOBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles), [BS_AUTO3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles), [BS_CHECKBOX](https://learn.microsoft.com/windows/desktop/Controls/button-styles), [BS_RADIOBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles), or [BS_3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) styles can be one of the values in the following table. If the button has any other style, the return value is zero.

| Return code | Description |
| --- | --- |
| **BST_CHECKED** | The button is checked. |
| **BST_INDETERMINATE** | The button is in an indeterminate state (applies only if the button has the [BS_3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) or [BS_AUTO3STATE](https://learn.microsoft.com/windows/desktop/Controls/button-styles) style). |
| **BST_UNCHECKED** | The button is not checked. |

## Remarks

The **IsDlgButtonChecked** function sends a [BM_GETCHECK](https://learn.microsoft.com/windows/desktop/Controls/bm-getcheck) message to the specified button control.

#### Examples

For an example, see the section titled "Creating a Modeless Dialog Box" in [Using Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

[CheckDlgButton](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-checkdlgbutton)