# IACList2::SetOptions

## Description

Sets the current autocomplete options.

## Parameters

### `dwFlag` [in]

Type: **DWORD**

New option flags. Use these flags to ask the client to include the names of the files and subfolders of the specified folders the next time the client's [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface is called. This parameter can contain one or more of the following flags.

#### ACLO_CURRENTDIR

Enumerate the current working directory.

#### ACLO_DESKTOP

Enumerate the Desktop folder.

#### ACLO_FAVORITES

Enumerate the Favorites folder.

#### ACLO_FILESYSONLY

Enumerate only those items that are part of the file system. Do not enumerate items contained by virtual folders.

#### ACLO_FILESYSDIRS

Enumerate only the file system directories, UNC shares, and UNC servers.

#### ACLO_MYCOMPUTER

Enumerate the My Computer folder.

#### ACLO_NONE

Do not enumerate anything.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## See also

[IACList2](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iaclist2)