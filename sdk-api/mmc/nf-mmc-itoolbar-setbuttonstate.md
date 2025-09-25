# IToolbar::SetButtonState

## Description

The **IToolbar::SetButtonState** method enables a snap-in to set an attribute of a button.

## Parameters

### `idCommand` [in]

A unique value that the snap-in has associated with a button using the
[InsertButton](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-itoolbar-insertbutton) or
[AddButtons](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-itoolbar-addbuttons) method using the
[MMCBUTTON](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmcbutton) structure.

### `nState` [in]

A value that specifies the state to be set for the button. Can be any one of the following:

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

### `bState` [in]

A value that specifies whether the state identified in nState is set to **TRUE** or **FALSE**. **TRUE** sets the button state to the state identified by nState and **FALSE** clears the state (if it is already set).

## Return value

This method can return one of these values.

## Remarks

Snap-ins should not set button states until the toolbar has been attached using
[IControlbar::Attach](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icontrolbar-attach).

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)