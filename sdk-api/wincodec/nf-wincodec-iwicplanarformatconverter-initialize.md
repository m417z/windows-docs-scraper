# IWICPlanarFormatConverter::Initialize

## Description

Initializes a format converter with a planar source, and specifies the interleaved output pixel format.

## Parameters

### `ppPlanes` [in]

Type: **[IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource)****

An array of [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) that represents image planes.

### `cPlanes`

Type: **UINT**

The number of component planes specified by the planes parameter.

### `dstFormat`

Type: **REFWICPixelFormatGUID**

The destination interleaved pixel format.

### `dither`

Type: **[WICBitmapDitherType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapdithertype)**

The [WICBitmapDitherType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapdithertype) used for conversion.

### `pIPalette`

Type: **[IWICPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicpalette)***

The palette to use for conversion.

### `alphaThresholdPercent`

Type: **double**

The alpha threshold to use for conversion.

### `paletteTranslate`

Type: **[WICBitmapPaletteType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmappalettetype)**

The palette translation type to use for conversion.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWICFormatConverter::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicplanarformatconverter-initialize)

[IWICPlanarFormatConverter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicplanarformatconverter)