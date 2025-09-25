# MMC_CONTROL_TYPE enumeration

## Description

The
MMC_CONTROL_TYPE enumeration defines the kinds of controls that can appear in the control bar. The values can be used in the nType parameter of the
[IControlbar::Attach](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontrolbar-attach) and
[IControlbar::Create](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontrolbar-create) methods.

## Constants

### `TOOLBAR:0`

The control to be associated with the control bar is a toolbar.

### `MENUBUTTON`

The control is a drop-down menu. This is a standard Win32 menu button.

### `COMBOBOXBAR`

Not implemented at this time. This is a standard Win32 combo box.

## See also

[IControlbar::Attach](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontrolbar-attach)

[IControlbar::Create](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontrolbar-create)