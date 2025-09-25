# _EXPCMDSTATE enumeration

## Description

**EXPCMDSTATE** values represent the command state of a Shell item.

## Constants

### `ECS_ENABLED:0`

The item is enabled.

### `ECS_DISABLED:0x1`

The item is unavailable. It might be displayed to the user as a dimmed, inaccessible item.

### `ECS_HIDDEN:0x2`

The item is hidden.

### `ECS_CHECKBOX:0x4`

The item is displayed with a check box and that check box is not checked.

### `ECS_CHECKED:0x8`

The item is displayed with a check box and that check box is checked. **ECS_CHECKED** is always returned with ECS_CHECKBOX.

### `ECS_RADIOCHECK:0x10`

**Windows 7 and later**. The item is one of a group of mutually exclusive options selected through a radio button. ECS_RADIOCHECK does not imply that the item is the selected option, though it might be.

## See also

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

[IExplorerCommand::GetState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorercommand-getstate)

[IExplorerCommandState::GetState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorercommandstate-getstate)