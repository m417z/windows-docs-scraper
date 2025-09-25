# IShellFolderViewDual3::get_FolderFlags

## Description

Gets the settings for the current folder.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

When this method returns, contains a pointer to the current setting flags. For a list of possible values, see [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.