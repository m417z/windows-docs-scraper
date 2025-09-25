# DXGK_GDIARG_CLEARTYPEBLEND structure

## Description

The **DXGK_GDIARG_CLEARTYPEBLEND** structure describes the characteristics of a GDI hardware-accelerated ClearType and antialiased text pixel blending operation.

## Members

### `DstRect` [in]

A [**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the bit-block transfer. The two points that define the rectangle are always well ordered.

The destination rectangle defined by **DstRect** can exceed the bounds of the destination surface, but sub-rectangles cannot. Additionally, all sub-rectangles are guaranteed to fit inside the destination surface. Sub-rectangles can be constrained further by a bounding rectangle that is smaller than the destination rectangle.

### `TmpSurfAllocationIndex`

[in] An index of the element in the allocation list that specifies a temporary surface. This surface can be used to read the destination before executing a pixel shader.

### `GammaSurfAllocationIndex`

[in] An index of the element in the allocation list that specifies a gamma table of type [**D3DKMDT_GDISURFACETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype). The format of the gamma lookup allocation is 8 bits per pixel, and the resolution is 512 x 16 pixels. Each row of the allocation contains two tables: gamma and inverse gamma. Each table has 256 entries.

### `AlphaSurfAllocationIndex`

[in] An index of the element in the allocation list that specifies alpha values of a surface. The alpha surface is in the same coordinate space as the destination surface space that is bounded by the **DstRect** destination rectangle.

### `DstAllocationIndex`

[in] An index of the element in the allocation list that specifies the allocation that is referenced by the **DstRect** destination rectangle.

### `DstToAlphaOffsetX`

[in] An offset in the x direction that transforms the destination rectangle coordinate space to the alpha surface coordinate space.

### `DstToAlphaOffsetY`

[in] An offset in the y direction that transforms the destination rectangle coordinate space to the alpha surface coordinate space.

### `Color`

[in] The foreground color, in 32-bit ARGB unsigned pixel format (as defined by the D3DDDIFMT_A8R8G8B8 value of the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration), corrected for gamma.

### `Gamma`

[in] An index of the element in the allocation list that specifies the gamma lookup table. Gamma values are in the range of [0, 15], otherwise gamma is 0xFFFFFFFF (the value of D3DKM_INVALID_GAMMA_INDEX). See Remarks for more information on how gamma is used in ClearType blending.

### `NumSubRects`

The number of sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `pSubRects`

A pointer to the sub-rectangles in the destination surface space that is bounded by the **DstRect** destination rectangle.

### `AlphaSurfPitch`

The pitch, in bytes, of the alpha surface referenced by **AlphaSurfAllocationIndex**.

### `Color2`

[in] The foreground color, in 32-bit ARGB unsigned pixel format (as defined by the D3DDDIFMT_A8R8G8B8 value of the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration), not corrected for gamma.

## Remarks

The value of **Gamma** should be in the range of [0, 15] unless set to 0xFFFFFFFF (the value of D3DKM_INVALID_GAMMA_INDEX). The value of **Gamma** is the index of a row in the gamma allocation.

When gamma is in the range of [0, 15], the following per-pixel blending is performed.

```cpp
GammaTable = (BYTE*)GammaSurfaceAddress + Gamma * GammaSurfacePitch;
InverseGammaTable = (BYTE*)GammaSurfaceAddress + Gamma * GammaSurfacePitch + 256;

Tmp.r = GammaTable[D.r]; // red
Tmp.g = GammaTable[D.g]; // green
Tmp.b = GammaTable[D.b]; // blue

BlendColor.r = InverseGammaTable[round((Tmp.r + (Color.r - Tmp.r) * A.r / 255.0))]
BlendColor.g = InverseGammaTable[round((Tmp.g + (Color.g - Tmp.g) * A.g / 255.0))]
BlendColor.b = InverseGammaTable[round((Tmp.b + (Color.b - Tmp.b) * A.b / 255.0))]
OutputColor.a = D.a

OutputColor.r = (A.r == 0) ? D.r : (A.r == 255) ? Color2.r : BlendColor.r;
OutputColor.g = (A.g == 0) ? D.g : (A.g == 255) ? Color2.g : BlendColor.g;
OutputColor.b = (A.b == 0) ? D.b : (A.b == 255) ? Color2.b : BlendColor.b;
```

When gamma is equal to 0xFFFFFFFF (the value of D3DKM_INVALID_GAMMA_INDEX), the following per-pixel blending is performed.

``` cpp
OutputColor.a = D.a
OutputColor.r = D.r + (Color.r - D.r) * (Color.r >= D.r ? A.r : A.g) / 255.0
OutputColor.g = D.g + (Color.g - D.g) * (Color.g >= D.g ? A.r : A.g) / 255.0
OutputColor.b = D.b + (Color.b - D.b) * (Color.b >= D.b ? A.r : A.g) / 255.0
```

Where the following parameters are in the D3DDDIFMT_A8R8G8B8 format defined in the [**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration:

* **Color** = gamma-corrected foreground color, as defined by the **Color** member
* **Color2** = foreground color, not gamma corrected, as defined by the **Color2** member
* *D* = destination pixel color
* *A* = alpha surface color

The display miniport driver must ensure that when a component of A is zero, the corresponding output component is the same as the background color component (D).

The driver must also ensure that when a component of A is 0xFF, the corresponding output component is the same as the foreground color component (**Color2**).

## See also

[**D3DDDIFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[**D3DKMDT_GDISURFACETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype)

[**RECT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)