# IActiveDesktop::SetWallpaper

## Description

Sets the wallpaper for the Active Desktop.

## Parameters

### `pwszWallpaper` [in]

Type: **PCWSTR**

A string value containing the file name of the wallpaper to be set.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)