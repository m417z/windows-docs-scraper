# MaskBlt function

## Description

The **MaskBlt** function combines the color data for the source and destination bitmaps using the specified mask and raster operation.

## Parameters

### `hdcDest` [in]

A handle to the destination device context.

### `xDest` [in]

The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `yDest` [in]

The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.

### `width` [in]

The width, in logical units, of the destination rectangle and source bitmap.

### `height` [in]

The height, in logical units, of the destination rectangle and source bitmap.

### `hdcSrc` [in]

A handle to the device context from which the bitmap is to be copied. It must be zero if the *dwRop* parameter specifies a raster operation that does not include a source.

### `xSrc` [in]

The x-coordinate, in logical units, of the upper-left corner of the source bitmap.

### `ySrc` [in]

The y-coordinate, in logical units, of the upper-left corner of the source bitmap.

### `hbmMask` [in]

A handle to the monochrome mask bitmap combined with the color bitmap in the source device context.

### `xMask` [in]

The horizontal pixel offset for the mask bitmap specified by the *hbmMask* parameter.

### `yMask` [in]

The vertical pixel offset for the mask bitmap specified by the *hbmMask* parameter.

### `rop` [in]

The foreground and background ternary raster operation codes (ROPs) that the function uses to control the combination of source and destination data. The background raster operation code is stored in the high-order byte of the high-order word of this value; the foreground raster operation code is stored in the low-order byte of the high-order word of this value; the low-order word of this value is ignored, and should be zero. The macro [MAKEROP4](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-makerop4) creates such combinations of foreground and background raster operation codes.

For a discussion of foreground and background in the context of this function, see the following Remarks section.

For a list of common raster operation codes (ROPs), see the [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) function. Note that the CAPTUREBLT ROP generally cannot be used for printing device contexts.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **MaskBlt** function uses device-dependent bitmaps.

A value of 1 in the mask specified by *hbmMask* indicates that the foreground raster operation code specified by *dwRop* should be applied at that location. A value of 0 in the mask indicates that the background raster operation code specified by *dwRop* should be applied at that location.

If the raster operations require a source, the mask rectangle must cover the source rectangle. If it does not, the function will fail. If the raster operations do not require a source, the mask rectangle must cover the destination rectangle. If it does not, the function will fail.

If a rotation or shear transformation is in effect for the source device context when this function is called, an error occurs. However, other types of transformation are allowed.

If the color formats of the source, pattern, and destination bitmaps differ, this function converts the pattern or source format, or both, to match the destination format.

If the mask bitmap is not a monochrome bitmap, an error occurs.

When an enhanced metafile is being recorded, an error occurs (and the function returns **FALSE**) if the source device context identifies an enhanced-metafile device context.

Not all devices support the **MaskBlt** function. An application should call the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function with the *nIndex* parameter as RC_BITBLT to determine whether a device supports this function.

If no mask bitmap is supplied, this function behaves exactly like [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt), using the foreground raster operation code.

**ICM:** No color management is performed when blits occur.

When used in a multiple monitor system, both *hdcSrc* and *hdcDest* must refer to the same device or the function will fail. To transfer data between DCs for different devices, convert the memory bitmap (compatible bitmap, or DDB) to a DIB by calling [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits). To display the DIB to the second device, call [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) or [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

## See also

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[PlgBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-plgblt)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)