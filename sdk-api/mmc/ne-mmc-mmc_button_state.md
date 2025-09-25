# MMC_BUTTON_STATE enumeration

## Description

The
**MMC_BUTTON_STATE** enumeration defines the possible states of buttons available in MMC. These values are used in the *nState* parameter of
[IConsoleVerb::GetVerbState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-getverbstate),
[IConsoleVerb::SetVerbState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-setverbstate),
[IToolbar::GetButtonState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-itoolbar-getbuttonstate), and
[IToolbar::SetButtonState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-itoolbar-setbuttonstate).

## Constants

### `ENABLED:0x1`

The button accepts user input. A button that does not have this state does not accept user input and appears dimmed.

### `CHECKED:0x2`

The button has the CHECKED style and is being pressed.

### `HIDDEN:0x4`

The button is not visible and cannot receive user input.

### `INDETERMINATE:0x8`

The button appears dimmed.

### `BUTTONPRESSED:0x10`

The button is being pressed.