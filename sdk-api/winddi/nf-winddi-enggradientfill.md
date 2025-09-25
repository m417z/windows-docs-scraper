# EngGradientFill function

## Description

The **EngGradientFill** function shades the specified primitives.

## Parameters

### `psoDest`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The **CLIPOBJ_***Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that is modified. Whenever possible, GDI simplifies the clipping involved.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure. This structure indicates how color indices should be translated between 32 bpp RGB format and the destination. The driver is responsible for converting the input COLOR16 color values to RGB.

### `pVertex`

Pointer to an array of TRIVERTEX structures, with each entry containing position and color information. The TRIVERTEX structure is described in the Microsoft Windows SDK documentation.

### `nVertex`

Specifies the number of TRIVERTEX structures in the array to which *pVertex* points.

### `pMesh`

Pointer to an array of structures that define the connectivity of the TRIVERTEX elements to which *pVertex* points.

When rectangles are being drawn, *pMesh* points to an array of GRADIENT_RECT structures, each of which specifies two TRIVERTEX elements that define a rectangle. The TRIVERTEX elements can represent any diagonally-opposed pair of rectangle vertices. Rectangle drawing is lower-right exclusive. Both TRIVERTEX and GRADIENT_RECT are defined in the Windows SDK documentation.

When triangles are being drawn, *pMesh* points to an array of GRADIENT_TRIANGLE structures, each of which specifies the three TRIVERTEX elements that define a triangle. Triangle drawing is lower-right exclusive. The GRADIENT_TRIANGLE structure is defined in the Windows SDK documentation.

### `nMesh`

Specifies the number of elements in the array to which *pMesh* points.

### `prclExtents`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area in which the gradient drawing is to occur. The points are specified in the coordinate system of the destination surface. This parameter is useful in estimating the size of the drawing operations.

### `pptlDitherOrg`

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin on the surface for dithering. The upper-left pixel of the dither pattern is aligned with this point.

### `ulMode` [in]

Specifies the current drawing mode and how to interpret the array to which *pMesh* points. This parameter can be one of the following values:

#### GRADIENT_FILL_RECT_H

The *pMesh* parameter points to an array of GRADIENT_RECT structures. Each rectangle is to be shaded from left to right.

#### GRADIENT_FILL_RECT_V

The *pMesh* parameter points to an array of GRADIENT_RECT structures. Each rectangle is to be shaded from top to bottom.

#### GRADIENT_FILL_TRIANGLE

The *pMesh* parameter points to an array of GRADIENT_TRIANGLE structures.

## Return value

**EngGradientFill** returns **TRUE** upon success. Otherwise, it reports an error and returns **FALSE**.

## Remarks

The driver should call **EngGradientFill** if it has hooked [DrvGradientFill](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgradientfill) and it is called to do something that it does not support.

The formulas used to compute the color value at each pixel depend on the value of *ulMode* as follows:

GDI ignores the alpha value of the vertices, leaving the alpha channel unchanged for surfaces that support alpha.

## See also

[DrvGradientFill](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgradientfill)