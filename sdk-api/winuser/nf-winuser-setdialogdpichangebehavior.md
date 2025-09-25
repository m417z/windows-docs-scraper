# SetDialogDpiChangeBehavior function

## Description

Dialogs in [Per-Monitor v2 contexts](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) are automatically DPI scaled. This method lets you customize their DPI change behavior.

This function works in conjunction with the [DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors) enum in order to override the default DPI scaling behavior for dialogs. This function is called on a specified dialog, for which the specified flags are individually saved.

This function does not affect the DPI scaling behavior for the child windows of the dialog in question - that is done with [SetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogcontroldpichangebehavior).

## Parameters

### `hDlg`

A handle for the dialog whose behavior will be modified.

### `mask`

A mask specifying the subset of flags to be changed.

### `values`

The desired value to be set for the specified subset of flags.

## Return value

This function returns TRUE if the operation was successful, and FALSE otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible errors are **ERROR_INVALID_HANDLE** if passed an invalid dialog HWND, and **ERROR_ACCESS_DENIED** if the dialog belongs to another process.

## Remarks

For extensibility, [DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors) was modeled as a set of bit-flags representing separate behaviors. This function follows the typical two-parameter approach to setting flags, where a mask specifies the subset of the flags to be changed.

It is not an error to call this API outside of Per Monitor v2 contexts, though the flags will have no effect on the behavior of the specified dialog until the context is changed to Per Monitor v2.

## See also

[DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors)

[GetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdialogdpichangebehavior)