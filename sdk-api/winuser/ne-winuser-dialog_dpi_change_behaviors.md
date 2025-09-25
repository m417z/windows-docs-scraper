# DIALOG_DPI_CHANGE_BEHAVIORS enumeration

## Description

In [Per Monitor v2 contexts](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context), dialogs will automatically respond to DPI changes by resizing themselves and re-computing the positions of their child windows (here referred to as re-layouting). This enum works in conjunction with [SetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogdpichangebehavior) in order to override the default DPI scaling behavior for dialogs.

This does not affect DPI scaling behavior for the child windows of dialogs (beyond re-layouting), which is controlled by [DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_control_dpi_change_behaviors).

## Constants

### `DDC_DEFAULT:0x0000`

The default behavior of the dialog manager. In response to a DPI change, the dialog manager will re-layout each control, update the font on each control, resize the dialog, and update the dialog's own font.

### `DDC_DISABLE_ALL:0x0001`

Prevents the dialog manager from responding to [WM_GETDPISCALEDSIZE](https://learn.microsoft.com/windows/desktop/hidpi/wm-getdpiscaledsize) and [WM_DPICHANGED](https://learn.microsoft.com/windows/desktop/hidpi/wm-dpichanged), disabling all default DPI scaling behavior.

### `DDC_DISABLE_RESIZE:0x0002`

Prevents the dialog manager from resizing the dialog in response to a DPI change.

### `DDC_DISABLE_CONTROL_RELAYOUT:0x0004`

Prevents the dialog manager from re-layouting all of the dialogue's immediate children HWNDs in response to a DPI change.

## See also

[DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_control_dpi_change_behaviors)

[GetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdialogdpichangebehavior)

[SetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogdpichangebehavior)