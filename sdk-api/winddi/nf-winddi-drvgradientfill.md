# DrvGradientFill function

## Description

The **DrvGradientFill** function shades the specified primitives.

## Parameters

### `psoDest` [in, out]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that is modified. Whenever possible, GDI simplifies the clipping involved.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure. This parameter should be ignored by the driver.

### `pVertex` [in]

Pointer to an array of TRIVERTEX structures, with each entry containing position and color information. The TRIVERTEX structure is described in the Microsoft Windows SDK documentation.

### `nVertex` [in]

Specifies the number of TRIVERTEX structures in the array to which *pVertex* points.

### `pMesh` [in]

Pointer to an array of structures that define the connectivity of the TRIVERTEX elements to which *pVertex* points.

When rectangles are being drawn, *pMesh* points to an array of GRADIENT_RECT structures, each of which specifies two TRIVERTEX elements that define a rectangle. The TRIVERTEX elements can represent any diagonally-opposed pair of rectangle vertices. Rectangle drawing is lower-right exclusive. Both TRIVERTEX and GRADIENT_RECT are defined in the Windows SDK documentation.

When triangles are being drawn, *pMesh* points to an array of GRADIENT_TRIANGLE structures, each of which specifies the three TRIVERTEX elements that define a triangle. Triangle drawing is lower-right exclusive. GRADIENT_TRIANGLE is defined in the Windows SDK documentation.

### `nMesh` [in]

Specifies the number of elements in the array to which *pMesh* points.

### `prclExtents` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area in which the gradient drawing is to occur. The points are specified in the coordinate system of the destination surface. This parameter is useful in estimating the size of the drawing operations.

### `pptlDitherOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin on the surface for dithering. The upper left pixel of the dither pattern is aligned with this point.

### `ulMode` [in]

Specifies the current drawing mode and how to interpret the array to which *pMesh* points. This parameter can be one of the following values:

#### GRADIENT_FILL_RECT_H

The *pMesh* parameter points to an array of GRADIENT_RECT structures. Each rectangle is to be shaded from left to right. Specifically, the upper-left and lower-left pixels are the same color, as are the upper-right and lower-right pixels.

#### GRADIENT_FILL_RECT_V

The *pMesh* parameter points to an array of GRADIENT_RECT structures. Each rectangle is to be shaded from top to bottom. Specifically, the upper-left and upper-right pixels are the same color, as are the lower-left and lower-right pixels.

#### GRADIENT_FILL_TRIANGLE

The *pMesh* parameter points to an array of GRADIENT_TRIANGLE structures.

The [gradient fill](https://learn.microsoft.com/windows-hardware/drivers/) calculations for each mode are documented in the Remarks section.

## Return value

**DrvGradientFill** returns **TRUE** upon success. Otherwise, it returns **FALSE** and reports an error by calling [EngSetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetlasterror).

## Remarks

**DrvGradientFill** can be optionally implemented in graphics drivers. GDI never calls this function for palletized surfaces.

The driver hooks **DrvGradientFill** by setting the HOOK_GRADIENTFILL flag when it calls [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface) or [EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface). If the driver has hooked **DrvGradientFill** and is called to perform an operation that it does not support, the driver should have GDI handle the operation by punting the data in a call to [EngGradientFill](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggradientfill).

GDI will not call **DrvGradientFill** for 8bpp destination surfaces.

The formulas for computing the color value at each pixel of the primitive depend on *ulMode* as follows:

The total error accumulated over all three color channels must not be more than eight (8). For more information about permissible error, see [Special Effects in Display Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/special-effects-in-display-drivers).

The driver should ignore the alpha value of the vertices, leaving the alpha channel unchanged for surfaces that support alpha blending.

## See also

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)

[EngGradientFill](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggradientfill)