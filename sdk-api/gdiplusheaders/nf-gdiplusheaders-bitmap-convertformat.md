# Bitmap::ConvertFormat

## Description

The **Bitmap::ConvertFormat** method converts a bitmap to a specified pixel format. The original pixel data in the bitmap is replaced by the new pixel data.

## Parameters

### `format` [in]

Type: **PixelFormat**

[Pixel format constant](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants) that specifies the new pixel format.

### `dithertype` [in]

Type: **[DitherType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-dithertype)**

Element of the [DitherType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-dithertype) enumeration that specifies the dithering algorithm. In cases where the conversion does not reduce the bit depth of the pixel data, pass **DitherTypeNone**.

### `palettetype` [in]

Type: **[PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype)**

Element of the [PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype) enumeration that specifies a standard palette to be used for dithering. If you are converting to a non-indexed format, this parameter is ignored. In that case, pass any element of the **PaletteType** enumeration, say **PaletteTypeCustom**.

### `palette` [in]

Type: **[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)***

Pointer to a [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) structure that specifies the palette whose indexes are stored in the pixel data of the converted bitmap. This palette (called the actual palette) does not have to have the type specified by the *palettetype* parameter. The *palettetype* parameter specifies a standard palette that can be used by any of the ordered or spiral dithering algorithms. If the actual palette has a type other than that specified by the *palettetype* parameter, then the **Bitmap::ConvertFormat** method performs a nearest-color conversion from the standard palette to the actual palette.

### `alphaThresholdPercent` [in]

Type: **REAL**

Real number in the range 0 through 100 that specifies which pixels in the source bitmap will map to the transparent color in the converted bitmap. A value of 0 specifies that none of the source pixels map to the transparent color. A value of 100 specifies that any pixel that is not fully opaque will map to the transparent color. A value of t specifies that any source pixel less than t percent of fully opaque will map to the transparent color. Note that for the alpha threshold to be effective, the palette must have a transparent color. If the palette does not have a transparent color, pixels with alpha values below the threshold will map to color that most closely matches (0, 0, 0, 0), usually black.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::InitializePalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-initializepalette)