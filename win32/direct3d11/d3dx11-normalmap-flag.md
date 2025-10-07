# D3DX11\_NORMALMAP\_FLAG enumeration

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

Normal map options. You can combine any number of these flags by using a bitwise OR operation.

## Constants

**D3DX11\_NORMALMAP\_MIRROR\_U**

Indicates that pixels off the edge of the texture on the U-axis should be mirrored, not wraped.

**D3DX11\_NORMALMAP\_MIRROR\_V**

Indicates that pixels off the edge of the texture on the V-axis should be mirrored, not wraped.

**D3DX11\_NORMALMAP\_MIRROR**

Same as D3DX11\_NORMALMAP\_MIRROR\_U \| D3DX11\_NORMALMAP\_MIRROR\_V.

**D3DX11\_NORMALMAP\_INVERTSIGN**

Inverts the direction of each normal.

**D3DX11\_NORMALMAP\_COMPUTE\_OCCLUSION**

Computes the per pixel occlusion term and encodes it into the alpha. An Alpha of 1 means that the pixel is not obscured in any way, and an alpha of 0 would mean that the pixel is completely obscured.

## Remarks

These flags are used by [**D3DX11ComputeNormalMap**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11computenormalmap).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-enums)

