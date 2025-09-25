# EngPlgBlt function

## Description

The **EngPlgBlt** function causes GDI to perform a rotate bit-block transfer.

## Parameters

### `psoTrg`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc`

Pointer to a SURFOBJ structure that describes the source surface for the bit-block transfer operation.

### `psoMsk`

Pointer to an optional SURFOBJ structure that represents a mask for the source. It is defined by a logic map, which is a bitmap with one bit per pixel.

This mask limits the area of the source that is copied. A mask has an implicit *rop4* of 0xCCAA, which means the source should be copied wherever the mask is 1, but the destination should be left alone wherever the mask is zero.

If this parameter is **NULL**, there is an implicit *rop4* of 0xCCCC, which means the source should be copied everywhere in the source rectangle.

The mask will always be large enough to contain the relevant source; tiling is unnecessary.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area of the destination to be modified. GDI functions enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. Unlike the [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) function, **EngPlgBlt** may be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines how color indices are translated between the source and target surfaces. This XLATEOBJ structure can be queried to find the RGB color for any source index.

A high quality rotate bit-block transfer is needed to interpolate colors.

### `pca`

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. For more information, see the Microsoft Windows SDK documentation.

### `pptlBrushOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the origin of the halftone brush. Drivers that use halftone brushes should align the upper left pixel of the brush's pattern with this point on the device surface.

### `pptfx`

Pointer to three POINTFIX structures that define a parallelogram in the destination surface. A fourth, implicit, vertex is given as: D = B + C − A. For a description of this data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

**EngPlgBlt** is never called with A, B, and C collinear.

### `prcl`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines, in the coordinate system of the source surface, the area to be copied. The points of the source rectangle are well ordered. **EngPlgBlt** will never be given an empty source rectangle.

### `pptl`

Pointer to a POINTL structure that specifies which pixel in the given mask corresponds to the upper-left pixel in the source rectangle. Ignore this parameter if *psoMsk* is **NULL**.

### `iMode` [in]

Defines how source pixels are combined to get output pixels. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, pixels should be combined with an AND operation. On a stretching bit-block transfer pixels should be replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, enough pixels should be ignored so that pixels need not be combined. On a stretching bit-block transfer, pixels should be replicated. |
| HALFTONE | The driver may use groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with an OR operation. On a stretching block transfers, pixels should be replicated. |

The methods WHITEONBLACK, BLACKONWHITE, and COLORONCOLOR are simple and provide compatibility for old applications, but do not produce the best looking results for color surfaces.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE** and an error code is reported.

## Remarks

**EngPlgBlt** performs only certain types of rotations.

This function performs bit-block transfers from a rectangle defined by *prcl* to any parallelogram. The parallelogram is defined by *pptfx*, which points to an array of three points.

The source rectangle at *prcl* is considered to be a geometric rectangle whose corners are displaced by (-0.5,-0.5) from the given integer coordinates. This exactly matches the source rectangle for [EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt). The source rectangle is always well ordered.

The upper-left corner of the source rectangle is mapped to the first point, A. The upper-right corner of the source rectangle is mapped to the second point, B. The lower-left corner of the source rectangle is mapped to the third point, C. The lower-right corner of the source rectangle is mapped to the implicit point in the parallelogram defined by treating the three given points as vectors and computing:

```
D = B + C - A
```

Note that a stretch blit can be expressed exactly as a parallelogram blit, but the coordinates given for the destination will be divisible by five.

## See also

[DrvAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvalphablend)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)