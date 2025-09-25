# ISearchFolderItemFactory::SetFolderLogicalViewMode

## Description

Sets folder logical view mode. The default settings are based on the `FolderTypeID` which is set by the [ISearchFolderItemFactory::SetFolderTypeID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isearchfolderitemfactory-setfoldertypeid) method.

## Parameters

### `flvm` [in]

Type: **[FOLDERLOGICALVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderlogicalviewmode)**

The [FOLDERLOGICALVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderlogicalviewmode) value.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.