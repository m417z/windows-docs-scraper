# GdiAlphaBlend function

## Description

The **GdiAlphaBlend** function displays bitmaps that have transparent or semitransparent pixels.

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

The x-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `yoriginSrc` [in]

The y-coordinate, in logical units, of the upper-left corner of the source rectangle.

### `wSrc` [in]

The width, in logical units, of the source rectangle.

### `hSrc` [in]

The height, in logical units, of the source rectangle.

### `ftn` [in]

The alpha-blending function for source and destination bitmaps, a global alpha value to be applied to the entire source bitmap, and format information for the source bitmap. The source and destination blend functions are currently limited to AC_SRC_OVER. See the [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction) and [EMRALPHABLEND](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emralphablend) structures.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

This function can return the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

**Note** This function is the same as [AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend).

If the source rectangle and destination rectangle are not the same size, the source bitmap is stretched to match the destination rectangle. If the [SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode) function is used, the *iStretchMode* value is automatically converted to COLORONCOLOR for this function (that is, BLACKONWHITE, WHITEONBLACK, and HALFTONE are changed to COLORONCOLOR).

The destination coordinates are transformed by using the transformation currently specified for the destination device context. The source coordinates are transformed by using the transformation currently specified for the source device context.

An error occurs (and the function returns **FALSE**) if the source device context identifies an enhanced metafile device context.

If destination and source bitmaps do not have the same color format, **GdiAlphaBlend** converts the source bitmap to match the destination bitmap.

**GdiAlphaBlend** does not support mirroring. If either the width or height of the source or destination is negative, this call will fail.

When rendering to a printer, first call [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) with SHADEBLENDCAPS to determine if the printer supports blending with **GdiAlphaBlend**. Note that, for a display DC, all blending operations are supported and these flags represent whether the operations are accelerated.

If the source and destination are the same surface, that is, they are both the screen or the same memory bitmap and the source and destination rectangles overlap, an error occurs and the function returns **FALSE**.

The source rectangle must lie completely within the source surface, otherwise an error occurs and the function returns **FALSE**.

**GdiAlphaBlend** fails if the width or height of the source or destination is negative.

The **SourceConstantAlpha** member of [BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction) specifies an alpha transparency value to be used on the entire source bitmap. The **SourceConstantAlpha** value is combined with any per-pixel alpha values. If **SourceConstantAlpha** is 0, it is assumed that the image is transparent. Set the **SourceConstantAlpha** value to 255 (which indicates that the image is opaque) when you only want to use per-pixel alpha values.

## See also

[BLENDFUNCTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-blendfunction)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[EMRALPHABLEND](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emralphablend)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)