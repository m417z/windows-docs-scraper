# DXGK_GDIARG_STRETCHBLT structure

## Description

The **DXGK_GDIARG_STRETCHBLT** structure describes the characteristics of a GDI hardware-accelerated stretch bit-block transfer (bitblt) operation.

## Members

### `SrcRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

The source rectangle will never exceed the bounds of the source surface, so it will never overhang the source surface.

This rectangle is mapped to the destination rectangle defined by **DstRect**.

For more information, see the Remarks section.

### `DstRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The destination rectangle defined by **DstRect** can exceed the bounds of the destination surface, but sub-rectangles cannot. Additionally, all sub-rectangles are guaranteed to fit inside the destination surface. Sub-rectangles can be constrained further by a bounding rectangle that is smaller than the destination rectangle.

For more information, see the Remarks section.

### `DstAllocationIndex` [in]

An index of the element in the allocation list that specifies the allocation that is referenced by the **DstRect** destination rectangle.

### `SrcAllocationIndex` [in]

An index of the element in the allocation list that specifies the allocation that is referenced by the SrcRect source rectangle.

### `NumSubRects`

The number of sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `pSubRects` [in]

A pointer to the sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `Mode` [in]

Specifies how source pixels are combined to produce output pixels based on whether the following values that are defined in *Wingdi.h* are set:

|Value|Meaning|
|--- |--- |
|BLACKONWHITE|On a shrinking bit-block transfer, pixels should be combined with a Boolean AND operation. On a stretching bit-block transfer, pixels should be replicated.|
|WHITEONBLACK|On a shrinking bit-block transfer, pixels should be combined with a Boolean OR operation. On a stretching bit-block transfer, pixels should be replicated.|

This type of operation will be processed only if the driver has set the **SupportMonoStretchBltModes** member in the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure.

### `MirrorX` [in]

Specifies whether the stretch bit-block transfer will be performed in mirror mode in the xdirection. This type of operation will be processed only if the value of **MirrorX** is nonzero and the driver has set the **SupportMirrorStretchBlt** member in the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure.

### `MirrorY` [in]

Specifies whether the stretch bit-block transfer will be performed in mirror mode in the y direction. This type of operation will be processed only if the value of **MirrorY** is nonzero and the driver has set the **SupportMirrorStretchBlt** member in the [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure.

### `Flags` [in]

Optional UINT value that can be used to debug driver code.

### `SrcPitch` [in]

The pitch of the source surface, in bytes.

## Remarks

The x and y stretch ratios are computed respectively as the ratios of the x and y sizes of the **DstRect** and **SrcRect** members.

The HALFTONE mode and STRETCH_HALFTONE modes that are defined in *Wingdi.h* will never be set in the **Mode** member. The COLORONCOLOR mode can be set in the [**DXGK_GDIARG_ALPHABLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_alphablend) and [**DXGK_GDIARG_TRANSPARENTBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_transparentblt) structures.

When sub-rectangles are transformed to the source surface space, the result is guaranteed to be within the source surface. The transformation of a sub-rectangle's coordinates in the destination surface to coordinates in the source surface is defined by the following formulas, where

* (Xd, Yd) is a point inside the sub-rectangle
* (Xs, Ys) is a point inside the source rectangle

```cpp
float Ws = SrcRect.right - SrcRect.left;
float Wd = DstRect.right - DstRect.left;
int Xs = round((Xd - DstRect.left + 0.5) * Ws/Wd + SrcRect.left - 0.5)
OR
int Xs = truncate((Xd - DstRect.left + 0.5) * Ws/Wd + SrcRect.left)

float Hs = SrcRect.bottom - SrcRect.top;
float Hd = DstRect.bottom - DstRect.top;
int Ys = round((Yd - DstRect.top + 0.5) * Hs/Hd + SrcRect.top - 0.5)
OR
int Ys = truncate((Yd - DstRect.top + 0.5) * Hs/Hd + SrcRect.top)
```

## See also

 [**DXGK_GDIARG_ALPHABLEND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_alphablend)

[**DXGK_GDIARG_TRANSPARENTBLT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gdiarg_transparentblt)

[**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)