# DXGK_GDIARG_BITBLT structure

## Description

The DXGK_GDIARG_BITBLT structure describes the characteristics of a GDI hardware-accelerated [bit-block transfer (bitblt)](https://learn.microsoft.com/windows-hardware/drivers/display/specifying-gdi-hardware-accelerated-rendering-operations) with no stretching.

## Members

### `SrcRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The source rectangle can exceed the bounds of the source surface.

This rectangle is mapped to the destination rectangle defined by **DstRect**. **SrcRect** is used to transform sub-rectangles from the source space to the destination space.

For more information, see the Remarks section.

### `DstRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The destination rectangle defined by **DstRect** can exceed the bounds of the destination surface, but sub-rectangles cannot. Additionally, all sub-rectangles are guaranteed to fit inside the destination surface. Sub-rectangles can be constrained further by a bounding rectangle that is smaller than the destination rectangle.

For more information, see the Remarks section.

### `SrcAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **SrcRect** source rectangle.

### `DstAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **DstRect** destination rectangle.

### `NumSubRects`

[in] The number of sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `pSubRects`

[in] A pointer to the sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `Rop`

[in] An 8-bit value that specifies a GDI raster operation (ROP) that is defined by the constant values of the [**DXGK_GDIROP_BITBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_gdirop_bitblt) enumeration.

### `Rop3`

[in] An 8-bit value that specifies a ternary GDI raster operation (ROP3) that combines a brush, a source bitmap, and a destination bitmap in one of 256 possible combinations. This type of raster operation will be processed only if the driver has set the **SupportAllBltRops** member in the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure.

### `SrcPitch`

[in] The pitch of the source surface, in bytes. For more information on using pitch, see Remarks section.

### `DstPitch`

[in] The pitch of the destination surface, in bytes. For more information on using pitch, see Remarks section.

## Remarks

The **SrcPitch** and **DstPitch** pitch values must be used to determine the byte locations of the **SrcRect** and **DstRect** rectangles, respectively, for the following allocations of type [**D3DKMDT_GDISURFACETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype):

D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE

D3DKMDT_GDISURFACE_EXISTINGSYSMEM

Pitch should be ignored for other allocation types.

Pitch is guaranteed to be aligned in the bit-block transfer according to the **AlignmentShift** member of the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure (that is, [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)**.PresentationCaps.AlignmentShift**).

Where a rectangle is defined by two pixels at coordinates (left, top) and (right, bottom), the address of the first pixel is:

```cpp
Allocation.BaseAddress + (top * Pitch) + (left * 4)
```

The address of the rectangle's last pixel is:

```cpp
Allocation.BaseAddress + ((bottom - 1) * Pitch) + ((right - 1) * 4)
```

When sub-rectangles are transformed to the source surface space, the result is guaranteed to be within the source surface. This transformation is defined by the following formula:

```cpp
<SrcSubRect.left = SubRect.left - DstRect.left + SrcRect.left;
SrcSubRect.right = SubRect.right - DstRect.left + SrcRect.left;
SrcSubRect.top = SubRect.top - DstRect.top + SrcRect.top;
SrcSubRect.bottom = SubRect.bottom - DstRect.top + SrcRect.top;
```

## See also

[**D3DKMDT_GDISURFACETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype)

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGK_GDIROP_BITBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_gdirop_bitblt)

[**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)