# DrvTransparentBlt function

## Description

The **DrvTransparentBlt** function provides bit-block transfer capabilities with transparency.

## Parameters

### `psoDst` [in, out]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the target surface on which to draw.

### `psoSrc` [in]

Pointer to the SURFOBJ structure that identifies the source surface of the bit-block transfer.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that is modified. Whenever possible, GDI simplifies the clipping involved.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that tells how the source color indices should be translated for writing to the target surface. If *pxlo* is **NULL**, no translation is needed.

### `prclDst` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

**DrvTransparentBlt** is never called with an empty destination rectangle.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the rectangular area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The source rectangle will never exceed the bounds of the source surface, and so will never overhang the source surface.

This rectangle is mapped to the destination rectangle defined by *prclDst*. **DrvTransparentBlt** is never called with an empty source rectangle.

### `iTransColor` [in]

Specifies the physical transparent color in the source surface format. For devices with palettes, this value is a palette index. For devices without palettes, this value is an RGB color in the format that is used in the source surface. For example, if the source surface format is in 5:6:5 RGB form, the value in this parameter will also be in the same form.

### `ulReserved` [in]

Reserved; this parameter must be set to zero.

## Return value

**DrvTransparentBlt** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

You can optionally implement the **DrvTransparentBlt** function in graphics drivers.

Bit-block transfer with transparency is supported between two device-managed surfaces or between a device-managed surface and a GDI-managed standard format bitmap. Driver writers are encouraged to support the case of blting from off-screen device bitmaps in video memory to other surfaces in video memory; all other cases can be punted to [EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt) with little performance penalty. The driver can punt calls involving device-managed surfaces to **EngTransparentBlt**.

Any pixels on the source surface that match the transparent color specified by *iTransColor* are not copied. For a detailed explanation of transparent blts, see [Copying Bitmaps](https://learn.microsoft.com/windows-hardware/drivers/display/copying-bitmaps).

The driver will never be called with overlapping source and destination rectangles on the same surface.

The driver should ignore any unused bits in the color key comparison, such as for the most significant bit when the bitmap format is 5:5:5 (five bits each of red, green, and blue).

The driver hooks **DrvTransparentBlt** by setting the HOOK_TRANSPARENTBLT flag when it calls [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). If the driver has hooked **DrvTransparentBlt** and is called to perform an operation that it does not support, the driver should have GDI handle the operation by forwarding the data in a call to [EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt).

## See also

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)