# MMCBUTTON structure

## Description

The
**MMCBUTTON** structure contains values used in creating buttons on a toolbar. This structure is similar to the **TBBUTTON** structure discussed in the Platform Software Development Kit (SDK) topics related to common controls.

## Members

### `nBitmap`

A value that specifies the zero-based index of a button image.

### `idCommand`

A value that specifies the command identifier returned when a button is clicked. This can be any integer value the user wants. Only the low word of the **int** is used.

### `fsState`

A value that specifies the button-state flags. This member can be any of the following values:

#### TBSTATE_CHECKED

The button has the TBSTYLE_CHECKED style and is being pressed.

#### TBSTATE_ENABLED

The button accepts user input. A button that does not have this state does not accept user input and appears dimmed.

#### TBSTATE_HIDDEN

The button is not visible and cannot receive user input.

#### TBSTATE_INDETERMINATE

The button appears dimmed.

#### TBSTATE_PRESSED

The button is being pressed.

### `fsType`

A value that specifies the button style. This member can be any combination of the following values:

#### TBSTYLE_BUTTON

Creates a standard push button.

#### TBSTYLE_CHECK

Creates a button that toggles between the pressed and not-pressed states each time the user clicks it. The button has a different background color when it is in the pressed state.

#### TBSTYLE_CHECKGROUP

Creates a check button that stays pressed until another button in the group is pressed.

#### TBSTYLE_GROUP

Creates a button that stays pressed until another button in the group is pressed.

#### TBSTYLE_SEP

Creates a separator, providing a small gap between button groups. A button that has this style does not receive user input.

### `lpButtonText`

A pointer to the text associated with a particular instance of the
**MMCBUTTON** structure.

### `lpTooltipText`

A pointer to the text for a particular tooltip.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)