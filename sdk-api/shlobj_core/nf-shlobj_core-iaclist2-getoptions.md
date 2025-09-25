# IACList2::GetOptions

## Description

Gets the current autocomplete options.

## Parameters

### `pdwFlag` [out]

Type: **DWORD***

A pointer to a value that will hold the current option flag when the method returns. This can be a combination of the following values.

#### ACLO_CURRENTDIR

Enumerate the current working directory.

#### ACLO_DESKTOP

Enumerate the Desktop folder.

#### ACLO_FAVORITES

Enumerate the Favorites folder.

#### ACLO_FILESYSONLY

Enumerate only items that are part of the file system. Do not enumerate items contained by virtual folders.

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