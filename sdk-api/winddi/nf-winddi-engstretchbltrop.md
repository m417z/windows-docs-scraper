# EngStretchBltROP function

## Description

The **EngStretchBltROP** function performs a stretching bit-block transfer using a [ROP](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `psoDest`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc`

Pointer to a SURFOBJ structure that describes the source surface for the bit-block transfer.

### `psoMask`

Pointer to a SURFOBJ structure that defines a mask for the source surface. The mask is defined by a logic map, which is a bitmap with 1 bit per pixel. Typically, a mask limits the area that is to be modified in the destination surface. This mask should always be the same size as the source surface.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area to be modified in the destination. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. However, unlike [EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt), **EngStretchBltROP** can be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices are to be translated between the source and target surfaces.

This XLATEOBJ structure can also be queried to find the RGB color for any source index. A high quality stretching bit-block transfer will need to interpolate colors in some cases.

### `pca`

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. For more information see the Windows SDK documentation.

### `pptlHTOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the halftone brush on the destination surface. When using halftone brushes, GDI aligns the upper left pixel of the brush's pattern at this point and repeats the brush according to its dimensions. GDI ignores this parameter if the *rop4* parameter does not require a pattern.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The two points that define the rectangle are not always well ordered, meaning the coordinates of the second point are not necessarily larger than those of the first point. If the destination rectangle is not well ordered, GDI makes it so.

The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the copy.

**EngStretchBltROP** must never be called with an empty destination rectangle.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the copy.

This rectangle maps to the rectangle to which *prclDest* points.

**EngStretchBltROP** must never be called with an empty source rectangle.

### `pptlMask`

Pointer to a POINTL structure that defines the pixel in the mask to which *prclMask* points. This pixel corresponds to the upper-left pixel in the source rectangle to which *prclSrc* points. This parameter is ignored if no mask is specified; that is, GDI ignores *pptlMask* when *prclMask* is **NULL**.

### `iMode` [in]

Specifies how source pixels are combined to get output pixels. The HALFTONE mode is slower than the other modes, but produces higher quality images. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, GDI combines pixels with a Boolean AND operation. On a stretching bit-block transfer, pixels are replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, GDI ignores enough pixels so that pixels need not be combined. On a stretching bit-block transfer, pixels are replicated. |
| HALFTONE | GDI uses groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with a Boolean OR operation. On a stretching bit-block transfer, pixels should be replicated. |

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure to be used to define the pattern for the bit-block transfer. GDI's [BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush) service routine retrieves the device's realization of the brush. GDI ignores this parameter if the *rop4* parameter does not require a pattern.

### `rop4` [in]

Represents a raster operation that defines how the mask, pattern, source, and destination pixels are combined to write an output pixel to the destination surface.

This is a quaternary raster operation, which is a natural extension of the usual ternary Rop3 operation. A Rop4 has 16 relevant bits, which are similar to the 8 defining bits of a Rop3. (The other redundant bits of the Rop3 are ignored.) The simplest way to implement a Rop4 is to consider its 2 bytes separately. The lower byte specifies a Rop3 that should be computed wherever the mask to which *psoMask* points is 1. The high byte specifies a Rop3 that can be computed and applied wherever the mask is zero.

## Return value

**EngStretchBltROP** returns **TRUE** upon success. Otherwise, it reports an error and returns **FALSE**.

## Remarks

The driver should call **EngStretchBltROP** if it has hooked [DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop) but cannot support all operations.

The mapping is defined by *prclSrc* and *prclDest*. The points specified in *prclDest* and *prclSrc* lie on integer coordinates that correspond to pixel centers. A rectangle defined by two such points is considered to be a geometric rectangle with two vertices whose coordinates are the given points, but with 0.5 subtracted from each coordinate. (POINTL structures are shorthand notation for specifying these fractional coordinate vertices.)

## See also

[DrvAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvalphablend)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)