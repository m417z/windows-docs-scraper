# IConsoleVerb::SetDefaultVerb

## Description

The
**SetDefaultVerb** method sets the default action on an object.

## Parameters

### `eCmdID` [in]

The default verb.

## Return value

This method can return one of these values.

## Remarks

The
[MMC_CONSOLE_VERB](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_console_verb) enumeration defines the set of default verbs. The snap-in can set any verb as the default verb. Setting a default verb causes MMC to:

* Show the context menu item for the verb in bold.
* Perform a default action (only for properties and open verbs) if the snap-in returns S_FALSE in its [MMCN_DBLCLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-dblclick) notification handler.

## See also

[IConsoleVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsoleverb)

[IConsoleVerb::GetDefaultVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-getdefaultverb)

[MMC_CONSOLE_VERB](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_console_verb)