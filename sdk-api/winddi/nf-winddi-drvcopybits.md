# DrvCopyBits function

## Description

The **DrvCopyBits** function translates between device-managed raster surfaces and GDI standard-format bitmaps.

## Parameters

### `psoDest`

Pointer to the destination [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure for the copy operation.

### `psoSrc`

Pointer to the source SURFOBJ structure for the copy operation.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines a clip region on the destination surface.

### `pxlo`

Pointer to an [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the translation of color indices between the source and target surfaces. If *pxlo* is **NULL**, no translation is needed.

### `prclDest`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area to be modified. This structure uses the coordinate system of the destination surface. The lower and right edges of this rectangle are not part of the bit-block transfer, meaning the rectangle is lower right exclusive.

**DrvCopyBits** is never called with an empty destination rectangle. The two points that define the rectangle are always well-ordered.

### `pptlSrc`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the upper-left corner of the source rectangle.

## Return value

The return value is **TRUE** if the source surface is successfully copied to the destination surface.

## Remarks

The driver may optionally hook **DrvCopyBits**. If so, GDI will call **DrvCopyBits** when it needs to copy from one surface to another and at least one of the surfaces is device-managed.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)