# SetDialogControlDpiChangeBehavior function

## Description

Overrides the default per-monitor DPI scaling behavior of a child window in a dialog.

## Parameters

### `hWnd`

A handle for the window whose behavior will be modified.

### `mask`

A mask specifying the subset of flags to be changed.

### `values`

The desired value to be set for the specified subset of flags.

## Return value

This function returns TRUE if the operation was successful, and FALSE otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible errors are **ERROR_INVALID_HANDLE** if passed an invalid HWND, and **ERROR_ACCESS_DENIED** if the windows belongs to another process.

## Remarks

The behaviors are specified as values from the [DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_control_dpi_change_behaviors) enum. This function follows the typical two-parameter approach to setting flags, where a mask specifies the subset of the flags to be changed.

It is valid to set these behaviors on *any* window. It does not matter if the window is currently a child of a dialog at the point in time that SetDialogControlDpiChangeBehavior is called. The behaviors are retained and will take effect only when the window is an immediate child of a dialog that has per-monitor DPI scaling enabled.

This API influences individual controls within dialogs. The dialog-wide per-monitor DPI scaling behavior is controlled by [SetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogdpichangebehavior).

## See also

[DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_control_dpi_change_behaviors)

[GetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdialogcontroldpichangebehavior)