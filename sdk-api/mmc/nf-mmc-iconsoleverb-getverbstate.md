# IConsoleVerb::GetVerbState

## Description

The
GetVerbState method enables a snap-in to obtain a given verb's current state.

## Parameters

### `eCmdID` [in]

A value that specifies the command identifier of the verb. Taken from the
[MMC_CONSOLE_VERB](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_console_verb) enumeration. This value cannot be MMC_VERB_NONE.

### `nState` [in]

A value that identifies the possible states of the button. Taken from the
[MMC_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_button_state) enumeration.

### `pState` [out]

A pointer to the state information returned. **TRUE** if the state is enabled or hidden and **FALSE** if the state is disabled or visible.

## Return value

This method can return one of these values.

## Remarks

When an item is selected, the verb states for all the commands are reset to disabled and hidden. It is up to the snap-in developer to update the verb state when an item is selected.

## See also

[IConsoleVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsoleverb)

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)