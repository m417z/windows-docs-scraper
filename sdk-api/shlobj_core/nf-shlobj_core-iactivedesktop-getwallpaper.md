# IActiveDesktop::GetWallpaper

## Description

Gets the current wallpaper.

## Parameters

### `pwszWallpaper` [out]

Type: **PWSTR**

When this method returns, contains a pointer to a null-terminated, Unicode buffer that contains the file name of the wallpaper.

### `cchWallpaper`

Type: **UINT**

The size of the *pwszWallpaper* string, in characters.

### `dwFlags`

Type: **DWORD**

The type of wallpaper to get. One of the following values.

#### AD_GETWP_BMP (0x00000000)

Get a bitmap.

#### AD_GETWP_IMAGE (0x00000001)

Get an image.

#### AD_GETWP_LAST_APPLIED (0x00000002)

Get the type of wallpaper that was last applied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.