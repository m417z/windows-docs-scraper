# IFolderView2::GetCurrentFolderFlags

## Description

Gets the currently applied folder flags.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

A pointer to a **DWORD** with any [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags) that have been applied to the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.