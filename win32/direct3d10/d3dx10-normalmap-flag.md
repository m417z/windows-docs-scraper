# D3DX10\_NORMALMAP\_FLAG enumeration

These flags are used to control how [**D3DX10ComputeNormalMap**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10computenormalmap) generates normal maps. Any number of these flags may be OR'd together in any combination.

## Constants

**D3DX10\_NORMALMAP\_MIRROR\_U**

Indicates that pixels off the edge of the texture on the U-axis should be mirrored, not wraped.

**D3DX10\_NORMALMAP\_MIRROR\_V**

Indicates that pixels off the edge of the texture on the V-axis should be mirrored, not wraped.

**D3DX10\_NORMALMAP\_MIRROR**

Same as D3DX10\_NORMALMAP\_MIRROR\_U \| D3DX10\_NORMALMAP\_MIRROR\_V.

**D3DX10\_NORMALMAP\_INVERTSIGN**

Inverts the direction of each normal.

**D3DX10\_NORMALMAP\_COMPUTE\_OCCLUSION**

Computes the per pixel occlusion term and encodes it into the alpha. An Alpha of 1 means that the pixel is not obscured in any way, and an alpha of 0 would mean that the pixel is completely obscured.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-enums)

