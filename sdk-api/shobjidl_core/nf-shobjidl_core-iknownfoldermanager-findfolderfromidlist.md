# IKnownFolderManager::FindFolderFromIDList

## Description

Gets an object that represents a known folder based on an IDList. The object allows you to query certain folder properties, get the current path of the folder, redirect the folder to another location, and get the path of the folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to the IDList.

### `ppkf` [out]

Type: **[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)****

When this method returns, contains the address of a pointer to the [IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder) object that represents the known folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))