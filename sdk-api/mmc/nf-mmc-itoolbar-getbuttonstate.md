# IToolbar::GetButtonState

## Description

The **IToolbar::GetButtonState** method enables a snap-in to obtain an attribute of a button.

## Parameters

### `idCommand` [in]

The command identifier of the toolbar button.

### `nState` [in]

A value that identifies the possible states of the button. Can be one of the following:

#### ENABLED

The button accepts user input. A button that does not have this state does not accept user input and appears dimmed.

#### CHECKED

The button has the CHECKED style and is being pressed.

#### HIDDEN

The button is not visible and cannot receive user input.

#### INDETERMINATE

The button appears dimmed.

#### BUTTONPRESSED

The button is being pressed.

### `pState` [out]

A pointer to the state information that is returned.

## Return value

This method can return one of these values.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)