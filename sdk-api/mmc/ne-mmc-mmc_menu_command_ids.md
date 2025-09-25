# MMC_MENU_COMMAND_IDS enumeration

## Description

The
**MMC_MENU_COMMAND_IDS** enumeration defines the Command Identifiers that are reserved by MMC.

## Constants

### `MMCC_STANDARD_VIEW_SELECT:-1`

Sent to a snap-in's
[IExtendContextMenu::Command](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-command) method when the user switches from a custom result view to the standard list view.

## Remarks

Typically, a snap-in's
[IExtendContextMenu::Command](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontextmenu-command) method is called only when one of its own menu items is selected. The MMCC_* codes are sent when a built-in menu item is selected and the snap-in must be notified about the selection. Other MMCC_* codes can be added later.

MMCC_STANDARD_VIEW_SELECT notifies the snap-in that the custom view is going away and that the snap-in can do any necessary clean-up. The next time the snap-in's
[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) method is called, the snap-in should return S_FALSE to indicate that the default list view should be used.