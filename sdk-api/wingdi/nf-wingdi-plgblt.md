# PlgBlt function

## Description

The **PlgBlt** function performs a bit-block transfer of the bits of color data from the specified rectangle in the source device context to the specified parallelogram in the destination device context. If the given bitmask handle identifies a valid monochrome bitmap, the function uses this bitmap to mask the bits of color data from the source rectangle.

## Parameters

### `hdcDest` [in]

A handle to the destination device context.

### `lpPoint` [in]

A pointer to an array of three points in logical space that identify three corners of the destination parallelogram. The upper-left corner of the source rectangle is mapped to the first point in this array, the upper-right corner to the second point in this array, and the lower-left corner to the third point. The lower-right corner of the source rectangle is mapped to the implicit fourth point in the parallelogram.

### `hdcSrc` [in]

A handle to the source device context.

### `xSrc` [in]

The x-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `ySrc` [in]

The y-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `width` [in]

The width, in logical units, of the source rectangle.

### `height` [in]

The height, in logical units, of the source rectangle.

### `hbmMask` [in]

A handle to an optional monochrome bitmap that is used to mask the colors of the source rectangle.

### `xMask` [in]

The x-coordinate, in logical units, of the upper-left corner of the monochrome bitmap.

### `yMask` [in]

The y-coordinate, in logical units, of the upper-left corner of the monochrome bitmap.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **PlgBlt** function works with device-dependent bitmaps.

The fourth vertex of the parallelogram (D) is defined by treating the first three points (A, B, and C ) as vectors and computing D = B +CA.

If the bitmask exists, a value of one in the mask indicates that the source pixel color should be copied to the destination. A value of zero in the mask indicates that the destination pixel color is not to be changed. If the mask rectangle is smaller than the source and destination rectangles, the function replicates the mask pattern.

Scaling, translation, and reflection transformations are allowed in the source device context; however, rotation and shear transformations are not. If the mask bitmap is not a monochrome bitmap, an error occurs. The stretching mode for the destination device context is used to determine how to stretch or compress the pixels, if that is necessary.

When an enhanced metafile is being recorded, an error occurs if the source device context identifies an enhanced-metafile device context.

The destination coordinates are transformed according to the destination device context; the source coordinates are transformed according to the source device context. If the source transformation has a rotation or shear, an error is returned.

If the destination and source rectangles do not have the same color format, **PlgBlt** converts the source rectangle to match the destination rectangle.

Not all devices support the **PlgBlt** function. For more information, see the description of the RC_BITBLT raster capability in the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function.

If the source and destination device contexts represent incompatible devices, **PlgBlt** returns an error.

When used in a multiple monitor system, both *hdcSrc* and *hdcDest* must refer to the same device or the function will fail. To transfer data between DCs for different devices, convert the memory bitmap to a DIB by calling [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits). To display the DIB to the second device, call [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) or [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits).

## See also

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[MaskBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-maskblt)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)