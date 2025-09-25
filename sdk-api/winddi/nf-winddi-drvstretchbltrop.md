# DrvStretchBltROP function

## Description

The **DrvStretchBltROP** function performs a stretching bit-block transfer using a [ROP](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `psoDest` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc` [in, out]

Pointer to a SURFOBJ structure that describes the source surface for the bit-block transfer.

### `psoMask` [in, optional]

Pointer to a SURFOBJ structure that defines a mask for the source. The mask is defined by a logic map, which is a bitmap with one bit per pixel. Typically, a mask limits the area to be modified in the destination surface. This mask is always the same size as the source surface.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area to be modified in the destination. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. However, unlike [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt), **DrvStretchBltROP** can be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices are to be translated between the source and target surfaces. If *pxlo* is **NULL**, no translation is needed.

This XLATEOBJ structure can also be queried to find the RGB color for any source index. A high quality stretching bit-block transfer will need to interpolate colors in some cases.

### `pca` [in, optional]

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. For more information see the Microsoft Windows SDK documentation.

### `pptlHTOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the halftone brush on the destination surface. When using halftone brushes, the driver should align the upper-left pixel of the brush with this point and repeat the brush according to its dimensions. The driver should ignore this parameter if the *rop4* parameter does not require a pattern.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The two points that define the rectangle are not always well ordered, meaning the coordinates of the second point are not necessarily larger than those of the first point. The driver should interchange the two *x* values and/or the two *y* values if the destination rectangle is not well ordered.

The rectangle is lower-right exclusive; that is, it lower and right edges are not a part of the copy.

**DrvStretchBltROP** is never called with an empty destination rectangle.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the copy.

The driver should map this rectangle to the rectangle defined by *prclDest*.

### `pptlMask` [in, optional]

Pointer to a POINTL structure that defines a pixel in the mask to which *prclMask* points. This pixel corresponds with the upper-left pixel in the source rectangle to which *prclSrc* points. The driver should ignore this parameter if no mask is specified.

### `iMode` [in]

Specifies how source pixels are combined to get output pixels. The HALFTONE mode is slower than the other modes, but produces higher quality images. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, pixels should be combined with a Boolean AND operation. On a stretching bit-block transfer, pixels should be replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, enough pixels should be ignored so pixels need not be combined. On a stretching bit-block transfer, pixels should be replicated. |
| HALFTONE | The driver can use groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with a Boolean OR operation. On a stretching bit-block transfer, pixels should be replicated. |

### `pbo` [in]

Pointer to the BRUSHOBJ structure to be used to define the pattern for the bit-block transfer. GDI's [BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush) service routine retrieves the device's realization of the brush. The driver can ignore this parameter if the *rop4* parameter does not require a pattern.

### `rop4` [in]

Represents a raster operation that defines how the mask, pattern, source, and destination pixels are combined to write an output pixel to the destination surface.

This is a quaternary raster operation, which is a natural extension of the usual ternary Rop3 operation. A Rop4 has 16 relevant bits, which are similar to the 8 defining bits of a Rop3. (The other redundant bits of the Rop3 are ignored.) The simplest way to implement a Rop4 is to consider its 2 bytes separately. The lower byte specifies a Rop3 that should be computed wherever the mask to which *psoMask* points is 1. The high byte specifies a Rop3 that can be computed and applied wherever the mask is zero.

## Return value

**DrvStretchBltROP** should return **TRUE** upon success. Otherwise, it should report an error code and return **FALSE**.

## Remarks

The mapping is defined by *prclSrc* and *prclDest*. The points specified in *prclDest* and *prclSrc* lie on integer coordinates, which correspond to pixel centers. A rectangle defined by two such points is considered to be a geometric rectangle with two vertices whose coordinates are the given points, but with 0.5 subtracted from each coordinate. (POINTL structures are shorthand notation for specifying these fractional coordinate vertices.)

The driver can optionally implement **DrvStretchBltROP**. If the driver does hook this call, it can call [EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop) to perform those stretching blit operations that it does not support.

## See also

[DrvAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvalphablend)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)