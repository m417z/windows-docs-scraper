# IKnownFolderManager::FindFolderFromPath

## Description

Gets an object that represents a known folder based on a file system path. The object allows you to query certain folder properties, get the current path of the folder, redirect the folder to another location, and get the path of the folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string of length MAX_PATH that contains a path to a known folder.

### `mode` [in]

Type: **[FFFP_MODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fffp_mode)**

One of the following values that specify the precision of the match of path and known folder:

#### FFFP_EXACTMATCH

Retrieve only the specific known folder for the given file path.

#### FFFP_NEARESTPARENTMATCH

If an exact match is not found for the given file path, retrieve the first known folder that matches one of its parent folders walking up the parent tree.

### `ppkf` [out]

Type: **[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)****

When this method returns, contains the address of a pointer to the [IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder) object that represents the known folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))