# DXGK_GDIARG_COLORFILL structure

## Description

The **DXGK_GDIARG_COLORFILL** structure describes the characteristics of a GDI hardware-accelerated color fill operation.

## Members

### `DstRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The destination rectangle defined by **DstRect** can exceed the bounds of the destination surface, but sub-rectangles cannot. Additionally, all sub-rectangles are guaranteed to fit inside the destination surface. Sub-rectangles can be constrained further by a bounding rectangle that is smaller than the destination rectangle.

### `DstAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **DstRect** destination rectangle.

### `NumSubRects`

[in] The number of sub-rectangles in the destination surface space. The sub-rectangles are not tightly bounded by the **DstRect** destination rectangle.

### `pSubRects`

[in] A pointer to the sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `Color`

[in] The fill color, in 32-bit ARGB unsigned pixel format (as defined by the D3DDDIFMT_A8R8G8B8 value of the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration).

### `Rop`

[in] An 8-bit value that specifies a GDI raster operation (ROP) that is defined by the constant values of the [**DXGK_GDIROP_COLORFILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_gdirop_colorfill) enumeration.

### `Rop3`

[in] An 8-bit value that specifies a ternary GDI raster operation (ROP3) that combines a brush, a source bitmap, and a destination bitmap in one of 256 possible combinations. This type of raster operation will be processed only if the driver has set the **SupportAllBltRops** member in the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure.

## See also

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**DXGK_GDIROP_COLORFILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_gdirop_colorfill)

[**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)