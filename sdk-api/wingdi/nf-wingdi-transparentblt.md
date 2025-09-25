# TransparentBlt function

## Description

The **TransparentBlt** function performs a bit-block transfer of the color data corresponding to a rectangle of pixels from the specified source device context into a destination device context.

## Parameters

### `hdcDest` [in]

A handle to the destination device context.

### `xoriginDest` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `yoriginDest` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `wDest` [in]

The width, in logical units, of the destination rectangle.

### `hDest` [in]

The height, in logical units, of the destination rectangle.

### `hdcSrc` [in]

A handle to the source device context.

### `xoriginSrc` [in]

The x-coordinate, in logical units, of the source rectangle.

### `yoriginSrc` [in]

The y-coordinate, in logical units, of the source rectangle.

### `wSrc` [in]

The width, in logical units, of the source rectangle.

### `hSrc` [in]

The height, in logical units, of the source rectangle.

### `crTransparent` [in]

The RGB color in the source bitmap to treat as transparent.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

The **TransparentBlt** function works with compatible bitmaps (DDBs).

The **TransparentBlt** function supports all formats of source bitmaps. However, for 32 bpp bitmaps, it just copies the alpha value over. Use [AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend) to specify 32 bits-per-pixel bitmaps with transparency.

If the source and destination rectangles are not the same size, the source bitmap is stretched to match the destination rectangle. When the [SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode) function is used, the *iStretchMode* modes of BLACKONWHITE and WHITEONBLACK are converted to COLORONCOLOR for the **TransparentBlt** function.

The destination device context specifies the transformation type for the destination coordinates. The source device context specifies the transformation type for the source coordinates.

**TransparentBlt** does not mirror a bitmap if either the width or height, of either the source or destination, is negative.

When used in a multiple monitor system, both *hdcSrc* and *hdcDest* must refer to the same device or the function will fail. To transfer data between DCs for different devices, convert the memory bitmap to a DIB by calling [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits). To display the DIB to the second device, call [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) or [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

## See also

[AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)