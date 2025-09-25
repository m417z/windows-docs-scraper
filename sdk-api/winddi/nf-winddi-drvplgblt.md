# DrvPlgBlt function

## Description

The **DrvPlgBlt** function provides rotate bit-block transfer capabilities between combinations of device-managed and GDI-managed surfaces.

## Parameters

### `psoTrg` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc` [in, out]

Pointer to a SURFOBJ structure that describes the source for the bit-block transfer operation.

### `psoMsk` [in, optional]

Pointer to an optional SURFOBJ structure that represents a mask for the source. It is defined by a logic map, which is a bitmap with one bit per pixel.

This mask limits the area of the source that is copied. A mask has an implicit *rop4* of 0xCCAA, which means the source should be copied wherever the mask is one, but the destination should be left alone wherever the mask is zero.

If this parameter is **NULL**, *rop4* is implicitly 0xCCCC, which means the source should be copied everywhere in the source rectangle.

The mask is always large enough to contain the relevant source; tiling is unnecessary.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area of the destination to be modified. GDI functions enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. Unlike the [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) function, **DrvPlgBlt** can be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines how color indices are translated between the source and target surfaces. The XLATEOBJ can also be queried to find the RGB color for any source index. If *pxlo* is **NULL**, no translation is needed.

A high quality rotate bit-block transfer is needed to interpolate colors.

### `pca` [in, optional]

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. For more information about this structure, see the Microsoft Windows SDK documentation.

### `pptlBrushOrg` [in, optional]

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that indicates the origin of the halftone brush. Device drivers that use halftone brushes should align the upper left pixel of the brush's pattern with this point on the device surface.

### `pptfx` [in]

Pointer to three POINTFIX structures that define a parallelogram in the destination surface. Define *pptfx*[0] as A, *pptfx*[1] as B, and *pptfx*[2] as C. A, B, and C define three vertices of a parallelogram. A fourth implicit vertex is given as:

```
    D = B + C − A
```

**DrvPlgBlt** is never called with A, B, and C collinear.

### `prcl` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area to be copied, in the coordinate system of the source surface. The points of the source rectangle are well ordered. **DrvPlgBlt** will never be given an empty source rectangle.

### `pptl` [in, optional]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies which pixel in the given mask corresponds to the upper-left pixel in the source rectangle. Ignore this parameter if no *psoMsk* is specified.

### `iMode` [in]

Defines how source pixels are combined to get output pixels. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, pixels should be combined with an AND operation. On a stretching bit-block transfer, pixels should be replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, enough pixels should be ignored so that pixels need not be combined. On a stretching bit-block transfer, pixels should be replicated. |
| HALFTONE | The driver can use groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with an OR operation. On a stretching bit-block transfer, pixels should be replicated. |

The methods WHITEONBLACK, BLACKONWHITE, and COLORONCOLOR provide compatibility for old applications, but do not produce the best results for color surfaces.

## Return value

**DrvPlgBlt** returns **TRUE** upon success. Otherwise, it reports an error and returns **FALSE**.

## Remarks

Similar to [DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt), **DrvPlgBlt** enables a device driver to write to GDI bitmaps, especially when the driver can do halftoning.

To transform the bitmap, this function performs bit-block transfers from a rectangle defined by *prcl* to any parallelogram. The parallelogram is defined by *pptfx*, which points to an array of three points.

The source rectangle at *prcl* is considered to be a geometric rectangle whose corners are displaced by (-0.5,-0.5) from the given integer coordinates. This exactly matches the source rectangle for [DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt). The source rectangle is always well ordered.

The upper-left corner of the source rectangle is mapped to the first point, A. The upper-right corner of the source rectangle is mapped to the second point, B. The lower-left corner of the source rectangle is mapped to the third point, C. The lower right corner of the source rectangle is mapped to the implicit point in the parallelogram defined by treating the three given points as vectors and computing:

```
    D = B + C - A
```

Note that a stretch blt can be expressed exactly as a parallelogram blt, but the coordinates given for the destination will have a fractional part of 0.5.

**DrvPlgBlt** is optional for graphics drivers. It is provided only for certain types of rotation. The driver should call [EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt) if **DrvPlgBlt** is called to perform operations it does not support.

## See also

[DrvAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvalphablend)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)