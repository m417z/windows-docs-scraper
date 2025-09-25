# FOLDER_ENUM_MODE enumeration

## Description

Used by [IObjectWithFolderEnumMode::GetMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iobjectwithfolderenummode-getmode) and [IObjectWithFolderEnumMode::SetMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iobjectwithfolderenummode-setmode) methods to get and set the display modes for the folders.

## Constants

### `FEM_VIEWRESULT:0`

 Display mode to view the contents of a folder.

### `FEM_NAVIGATION:1`

 Display mode to view the contents of the folders in the navigation pane.

## Remarks

If an item does not support the enumeration mode value (because it is not a folder or it does not provide the enumeration mode) then it is created in the default enumeration mode.