# EngCopyBits function

## Description

The **EngCopyBits** function translates between device-managed raster surfaces and GDI standard-format bitmaps.

## Parameters

### `psoDest`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the destination surface for the copy operation.

### `psoSrc`

Pointer to a SURFOBJ structure that describes the source surface for the copy operation.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that restricts the area of the destination surface that will be affected. This parameter can be **NULL**.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the translation of color indices between the source and target surfaces.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area in the coordinate system of the destination surface that will be modified. The rectangle is lower-right exclusive, meaning the lower and right edges of this rectangle are not part of the copy.

### `pptlSrc` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the upper left corner of the source rectangle.

## Return value

The return value is **TRUE** if the function is successful. If it is unsuccessful, it logs an error and returns **FALSE**.

## Remarks

Standard-format bitmaps are single-plane, packed-pixel format. Each scan line is aligned on a 4-byte boundary. These bitmaps have 1, 4, 8, 16, 24, or 32 bits per pixel. See the [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap) function for a list of standard format types.

GDI calls this function from its simulations.

**EngCopyBits** should not be called with an empty destination rectangle, and the two points of the destination rectangle must be well-ordered; that is, the first point should represent the upper-left vertex of the rectangle, and the second should represent the lower-right vertex.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)