# DXGK_GDIARG_TRANSPARENTBLT structure

## Description

The **DXGK_GDIARG_TRANSPARENTBLT** structure describes the characteristics of a GDI hardware-accelerated bit-block transfer (bitblt) operation with transparency.

## Members

### `SrcRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be copied. This rectangle is specified in the coordinate system of the source surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered.

For more information, see the Remarks section.

### `DstRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The destination rectangle defined by **DstRect** can exceed the bounds of the destination surface, but sub-rectangles cannot. Additionally, all sub-rectangles are guaranteed to fit inside the destination surface. Sub-rectangles can be constrained further by a bounding rectangle that is smaller than the destination rectangle.

For more information, see the Remarks section.

### `SrcAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **SrcRect** source rectangle.

### `DstAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **DstRect** destination rectangle.

### `Color`

[in] Specifies the physical transparent color in the source surface, in 32-bit ARGB unsigned pixel format (as defined by the D3DDDIFMT_A8R8G8B8 value of the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration). Any pixels on the source surface that match the transparent color that is specified by **Color** are not copied.

### `NumSubRects`

[in] The number of sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `pSubRects`

[in] A pointer to the sub-rectangles in the destination surface space.

### `Flags`

[in] A [**D3DKM_TRANSPARENTBLTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_d3dkm_transparentbltflags) structure that specifies the display adapter's hardware-accelerated transparent bit-block transfer capabilities.

### `SrcPitch`

[in] The pitch of the source surface, in bytes.

## Remarks

The rectangles that are specified by the **SrcRect** and **DstRect** members bound all sub-rectangles in the source and destination surface spaces, respectively. The Microsoft DirectX graphics kernel subsystem will never request a transparent bit-block transfer if the source and destination rectangles overlap on the same surface.

To complete the transparent bit-block transfer operation, the color of each pixel in **DstRect** should be computed by using the following formula:

```cpp
typedef DXGK_GDIARG_TRANSPARENTBLT tblt;
if (tblt.Flags.HonorAlpha)
{
  if (SourceColor != tblt.Color)
 {
  DestinationColor = SourceColor;
 }
}
else
{
 if ((SourceColor & 0x00FFFFFF) != tblt.Color)
 {
  DestinationColor = SourceColor;
 }
}
```

In this case, a value of 0x00FFFFFF in ARGB format indicates alpha = 0, hence alpha-blending is not implemented.

If a stretch bit-block transfer operation is required, the x and y stretch ratios are computed respectively as the ratios of the x and y sizes of **DstRect** and **SrcRect**. Additionally, the stretch operation will proceed as if the COLORONCOLOR value in *Wingdi.h* is set. In a shrinking bit-block transfer, enough pixels should be ignored so that pixels do not need to be combined. In a stretching bit-block transfer, pixels should be replicated.

For more information about transparent bit-block transfers, see [Copying Bitmaps](https://learn.microsoft.com/windows-hardware/drivers/display/copying-bitmaps).

When sub-rectangles are transformed to the source surface space, the result is guaranteed to be within the source surface. The transformation of a sub-rectangle's coordinates in the destination surface to coordinates in the source surface is defined by the following formulas, where:

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

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**D3DKM_TRANSPARENTBLTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_d3dkm_transparentbltflags)

[**DXGK_RENDERKM_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_renderkm_command)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)