# EngBitBlt function

## Description

The **EngBitBlt** function provides general bit-block transfer capabilities either between [device-managed surfaces](https://learn.microsoft.com/windows-hardware/drivers/), or between a device-managed surface and a GDI-managed standard format bitmap.

## Parameters

### `psoTrg`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `psoSrc`

If the *rop4* requires it, pointer to a SURFOBJ structure that defines the source for the bit-block transfer operation.

### `psoMask`

Pointer to a SURFOBJ structure that defines a surface to be used as a mask. The mask is defined as a bitmap with 1 bit per pixel. Typically, a mask limits the area that is to be modified in the destination surface. Masking is selected by a *rop4* with the value 0xAACC. The destination surface is unaffected when the mask is zero.

The mask is large enough to cover the destination rectangle.

If the value of this parameter is **NULL** and a mask is required by the *rop4*, then the implicit mask in the brush is used. If a mask is required, then *psoMask* overrides the implicit mask in the brush.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that will be modified. Whenever possible, GDI simplifies the clipping involved; for example, this function is never called with a single clipping rectangle. GDI clips the destination rectangle before calling this function, making additional clipping unnecessary.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that tells how color indices should be translated between the source and target surfaces.

### `prclTrg`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure in the coordinate system of the destination surface that defines the area to be modified. The rectangle is defined by two points; upper left and lower right. The lower and right edges of this rectangle are not part of the bit-block transfer, meaning the rectangle is lower right exclusive.

**EngBitBlt** is never called with an empty destination rectangle. The two points that define the rectangle are always well ordered.

### `pptlSrc`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the upper left corner of the source rectangle, if a source exists. If there is no source, the driver should ignore this parameter.

### `pptlMask`

Pointer to a POINTL structure that defines which pixel in the mask corresponds to the upper left corner of the destination rectangle. If no mask is specified in *psoMask* the driver should ignore this parameter.

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure to be used to define the pattern for the bit-block transfer. GDI's [BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush) service routine retrieves the device's realization of the brush. The driver can ignore this parameter if the *rop4* parameter does not require a pattern.

### `pptlBrush`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the brush in the destination surface. The upper left pixel of the brush is aligned at this point and the brush repeats according to its dimensions. Ignore this parameter if the *rop4* parameter does not require a pattern.

### `rop4` [in]

Represents a raster operation that defines how the mask, pattern, source, and destination pixels are combined to write an output pixel to the destination surface.

This is a quaternary raster operation, which is a natural extension of the usual ternary Rop3 operation. A Rop4 has 16 relevant bits, which are similar to the 8 defining bits of a Rop3. (The other, redundant bits of the Rop3 are ignored.) The simplest way to implement a Rop4 is to consider its 2 bytes separately. The lower byte specifies a Rop3 that should be computed wherever the mask is 1. The high byte specifies a Rop3 that can be computed and applied wherever the mask is 0.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

If a device's surface is organized as a standard-format bitmap, the driver can request that GDI perform the bit-block transfer by calling **EngBitBlt**. A driver might do this if it has special hardware to handle simple transfers quickly, but doesn't want to handle calls with complicated transfers.

See the Microsoft Windows SDK documentation for more information about raster operations.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)