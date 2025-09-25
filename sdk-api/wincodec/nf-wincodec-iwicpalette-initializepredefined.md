# IWICPalette::InitializePredefined

## Description

Initializes the palette to one of the pre-defined palettes specified by [WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype) and optionally adds a transparent color.

## Parameters

### `ePaletteType` [in]

Type: **[WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype)**

The desired pre-defined palette type.

### `fAddTransparentColor` [in]

Type: **BOOL**

The optional transparent color to add to the palette. If no transparent color is needed, use 0. When initializing to a grayscale or black and white palette, set this parameter to **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a transparent color is added to a palette, the palette is no longer predefined and is returned as [WICBitmapPaletteTypeCustom](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype). For palettes with less than 256 entries, the transparent entry is added to the end of the palette (that is, a 16-color palette becomes a 17-color palette). For palettes with 256 colors, the transparent palette entry will replace the last entry in the pre-defined palette.