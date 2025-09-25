# IKnownFolderManager::GetFolderByName

## Description

Gets an object that represents a known folder identified by its canonical name. The object allows you to query certain folder properties, get the current path of the folder, redirect the folder to another location, and get the path of the folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

## Parameters

### `pszCanonicalName` [in]

Type: **LPCWSTR**

A pointer to the non-localized, canonical name for the known folder, stored as a null-terminated Unicode string. If this folder is a [common](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) or [per-user](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) folder, this value is also used as the value name of the "User Shell Folders" registry settings. This value is retrieved through the **pszName** member of the folder's [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure.

### `ppkf` [out]

Type: **[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)****

When this method returns, contains the address of a pointer to the [IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder) object that represents the known folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

### When to Use

Use this method when you know exactly which known folder you are looking for and want to access it directly.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))