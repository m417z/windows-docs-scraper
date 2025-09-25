# EXPLORER_BROWSER_FILL_FLAGS enumeration

## Description

These flags are used with [IExplorerBrowser::FillFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-fillfromobject).

## Constants

### `EBF_NONE:0`

No flags.

### `EBF_SELECTFROMDATAOBJECT:0x100`

Causes [IExplorerBrowser::FillFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iexplorerbrowser-fillfromobject) to first populate the results folder with the contents of the parent folders of the items in the data object, and then select only the items that are in the data object.

### `EBF_NODROPTARGET:0x200`

Do not allow dropping on the folder. In other words, do not register a drop target for the view. Applications can then register their own drop targets.