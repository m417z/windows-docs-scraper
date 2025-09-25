# FOLDERLOGICALVIEWMODE enumeration

## Description

Used by [IFolderViewSettings::GetViewMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderviewsettings-getviewmode) and [ISearchFolderItemFactory::SetFolderLogicalViewMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isearchfolderitemfactory-setfolderlogicalviewmode) to describe the view mode.

## Constants

### `FLVM_UNSPECIFIED:-1`

The view is not specified.

### `FLVM_FIRST:1`

The minimum valid enumeration value. Used for validation purposes only.

### `FLVM_DETAILS:1`

Details view.

### `FLVM_TILES:2`

Tiles view.

### `FLVM_ICONS:3`

Icons view.

### `FLVM_LIST:4`

**Windows 7 and later**. List view.

### `FLVM_CONTENT:5`

**Windows 7 and later**. Content view.

### `FLVM_LAST:5`

The maximum valid enumeration value. Used for validation purposes only.