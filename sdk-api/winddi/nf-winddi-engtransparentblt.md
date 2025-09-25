# EngTransparentBlt function

## Description

The **EngTransparentBlt** function provides bit-block transfer capabilities with transparency.

## Parameters

### `psoDst` [in]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the target surface on which to draw.

### `psoSrc` [in]

Pointer to the SURFOBJ structure that identifies the source surface of the bit-block transfer.

### `pco` [in, optional]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that is modified. Whenever possible, GDI simplifies the clipping involved.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that tells how the source color indices should be translated for writing to the target surface.

### `prclDst` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The driver must never call **EngTransparentBlt** with an empty destination rectangle.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the rectangular area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The source rectangle will never exceed the bounds of the source surface, and so will never overhang the source surface.

This rectangle is mapped to the destination rectangle defined by *prclDst*. The driver must never call **EngTransparentBlt** with an empty source rectangle.

### `TransColor` [in]

Specifies the physical transparent color, in the source surface's format. This is a color index value that has been translated to the source surface's palette. For more information, see the **Remarks** section.

### `bCalledFromBitBlt` [in]

Reserved. This parameter must be set to zero.

## Return value

**EngTransparentBlt** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

The driver should call **EngTransparentBlt** if it has hooked [DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt) and it is called to do something that it does not support.

Bit-block transfer with transparency is supported between two [device-managed surfaces](https://learn.microsoft.com/windows-hardware/drivers/) or between a device-managed surface and a GDI-managed standard format bitmap. Currently, GDI supports only BMF_4BPP and BMF_8BPP source surfaces.

The pixels on the source surface that match the transparent color specified by *iTransparentColor* are not copied. For a detailed explanation of transparent blts, see [Copying Bitmaps](https://learn.microsoft.com/windows-hardware/drivers/display/copying-bitmaps).

## See also

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)