# FolderActionSteps enumeration

## Description

Defines the action that the data manager takes when both the age and size limits are met.

## Constants

### `plaCreateCab:0x1`

Creates a cabinet file. The name of the cabinet file is *nameofthesubfolder*.cab.

### `plaDeleteData:0x2`

Deletes all files in the folder, except the report and cabinet file.

### `plaSendCab:0x4`

Sends the cabinet file to the location specified in the [IFolderAction::SendCabTo](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ifolderaction-get_sendcabto) property.

### `plaDeleteCab:0x8`

Deletes the cabinet file.

### `plaDeleteReport:0x10`

Deletes the report file.

## Remarks

Specify one or more actions. The data manager applies the actions in the order in which they are defined in this enumeration.

## See also

[IFolderAction::Actions](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ifolderaction-get_actions)