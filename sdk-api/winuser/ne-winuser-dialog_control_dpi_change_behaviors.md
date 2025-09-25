# DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS enumeration

## Description

Describes per-monitor DPI scaling behavior overrides for child windows within dialogs. The values in this enumeration are bitfields and can be combined.

## Constants

### `DCDC_DEFAULT:0x0000`

The default behavior of the dialog manager. The dialog managed will update the font, size, and position of the child window on DPI changes.

### `DCDC_DISABLE_FONT_UPDATE:0x0001`

Prevents the dialog manager from sending an updated font to the child window via WM_SETFONT in response to a DPI change.

### `DCDC_DISABLE_RELAYOUT:0x0002`

Prevents the dialog manager from resizing and repositioning the child window in response to a DPI change.

## Remarks

This enum is used with [SetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogcontroldpichangebehavior) in order to override the default per-monitor DPI scaling behavior for a child window within a dialog.

These settings only apply to individual controls within dialogs. The dialog-wide per-monitor DPI scaling behavior of a dialog is controlled by [DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors).

## See also

[DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors)

[GetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdialogcontroldpichangebehavior)

[SetDialogControlDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogcontroldpichangebehavior)