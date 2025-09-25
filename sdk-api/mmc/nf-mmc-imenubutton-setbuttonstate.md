# IMenuButton::SetButtonState

## Description

The **IMenuButton::SetButtonState** method enables a user to change the state of a menu button.

## Parameters

### `idCommand` [in]

A value that specifies a user-supplied value that uniquely identifies the menu button in which the state is being changed.

### `nState` [in]

A value that specifies the state of the button. This value can be one of the following values taken from the
[MMC_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_button_state) enumeration:

#### ENABLED

The button accepts user input. A button that does not have this state does not accept user input and appears dimmed.

#### HIDDEN

The button is not visible and cannot receive user input.

### `bState` [in]

A value that specifies whether the state is to be turned on or off. **TRUE** indicates that the button state is on; otherwise, set to **FALSE**.

## Return value

This method can return one of these values.

## See also

[IMenuButton](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-imenubutton)