# ISearchFolderItemFactory::SetScope

## Description

Sets search scope, as specified.

## Parameters

### `psiaScope` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to the list of locations to search. The search will include this location and all its subcontainers. The default is **FOLDERID_Profile**

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.