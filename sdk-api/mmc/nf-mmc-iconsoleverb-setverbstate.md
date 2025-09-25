# IConsoleVerb::SetVerbState

## Description

The
SetVerbState method enables a snap-in to set a given verb's button state.

## Parameters

### `eCmdID` [in]

A value that specifies the command identifier of the verb. Values are taken from the
[MMC_CONSOLE_VERB](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_console_verb) enumeration. This value cannot be MMC_VERB_NONE.

### `nState` [in]

Identifies the possible states of the button. Taken from the
[MMC_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_button_state) enumeration.

### `bState` [in]

This value is **TRUE** to enable or hide the verb, **FALSE** to disable or show the selected verb.

## Return value

This method can return one of these values.

## Remarks

## See also

[IConsoleVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsoleverb)