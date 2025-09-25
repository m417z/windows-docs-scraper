# StretchBlt function

## Description

The **StretchBlt** function copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary. The system stretches or compresses the bitmap according to the stretching mode currently set in the destination device context.

## Parameters

### `hdcDest` [in]

A handle to the destination device context.

### `xDest` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `yDest` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `wDest` [in]

The width, in logical units, of the destination rectangle.

### `hDest` [in]

The height, in logical units, of the destination rectangle.

### `hdcSrc` [in]

A handle to the source device context.

### `xSrc` [in]

The x-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `ySrc` [in]

The y-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `wSrc` [in]

The width, in logical units, of the source rectangle.

### `hSrc` [in]

The height, in logical units, of the source rectangle.

### `rop` [in]

The raster operation to be performed. Raster operation codes define how the system combines colors in output operations that involve a brush, a source bitmap, and a destination bitmap.

See [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) for a list of common raster operation codes (ROPs). Note that the CAPTUREBLT ROP generally cannot be used for printing device contexts.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

**StretchBlt** stretches or compresses the source bitmap in memory and then copies the result to the destination rectangle. This bitmap can be either a compatible bitmap (DDB) or the output from [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection). The color data for pattern or destination pixels is merged after the stretching or compression occurs.

When an enhanced metafile is being recorded, an error occurs (and the function returns **FALSE**) if the source device context identifies an enhanced-metafile device context.

If the specified raster operation requires a brush, the system uses the brush currently selected into the destination device context.

The destination coordinates are transformed by using the transformation currently specified for the destination device context; the source coordinates are transformed by using the transformation currently specified for the source device context.

If the source transformation has a rotation or shear, an error occurs.

If destination, source, and pattern bitmaps do not have the same color format, **StretchBlt** converts the source and pattern bitmaps to match the destination bitmap.

If **StretchBlt** must convert a monochrome bitmap to a color bitmap, it sets white bits (1) to the background color and black bits (0) to the foreground color. To convert a color bitmap to a monochrome bitmap, it sets pixels that match the background color to white (1) and sets all other pixels to black (0). The foreground and background colors of the device context with color are used.

**StretchBlt** creates a mirror image of a bitmap if the signs of the *nWidthSrc* and *nWidthDest* parameters or if the *nHeightSrc* and *nHeightDest* parameters differ. If *nWidthSrc* and *nWidthDest* have different signs, the function creates a mirror image of the bitmap along the x-axis. If *nHeightSrc* and *nHeightDest* have different signs, the function creates a mirror image of the bitmap along the y-axis.

Not all devices support the **StretchBlt** function. For more information, see the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps).

**ICM:** No color management is performed when a blit operation occurs.

When used in a multiple monitor system, both *hdcSrc* and *hdcDest* must refer to the same device or the function will fail. To transfer data between DCs for different devices, convert the memory bitmap to a DIB by calling [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits). To display the DIB to the second device, call [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) or [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

#### Examples

For an example, see [Scaling an Image](https://learn.microsoft.com/windows/desktop/gdi/scaling-an-image).

## See also

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt)

[PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)