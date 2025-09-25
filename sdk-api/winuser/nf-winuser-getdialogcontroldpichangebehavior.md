# GetDialogControlDpiChangeBehavior function

## Description

Retrieves and per-monitor DPI scaling behavior overrides of a child window in a dialog.

## Parameters

### `hWnd`

The handle for the window to examine.

## Return value

The flags set on the given window. If passed an invalid handle, this function will return zero, and set its [last error](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to **ERROR_INVALID_HANDLE**.

## See also

[DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_control_dpi_change_behaviors)

[SetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogcontroldpichangebehavior)