# IWICPalette::GetType

## Description

Retrieves the [WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype) that describes the palette.

## Parameters

### `pePaletteType` [out]

Type: **[WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype)***

Pointer that receives the palette type of the bimtap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**WICBitmapPaletteCustom** is used for palettes initialized from both [InitializeCustom](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicpalette-initializecustom) and [InitializeFromBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicpalette-initializefrombitmap). There is no distinction is made between optimized and custom palettes.