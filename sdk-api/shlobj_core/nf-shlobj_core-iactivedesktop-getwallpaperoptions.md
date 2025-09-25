# IActiveDesktop::GetWallpaperOptions

## Description

Gets the wallpaper options.

## Parameters

### `pwpo` [in, out]

Type: **LPWALLPAPEROPT**

The address of a [WALLPAPEROPT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-wallpaperopt) structure containing the options currently set.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)