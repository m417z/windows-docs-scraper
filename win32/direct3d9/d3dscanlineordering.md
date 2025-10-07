# D3DSCANLINEORDERING enumeration

Flags indicating the method the rasterizer uses to create an image on a surface.

## Constants

**D3DSCANLINEORDERING\_PROGRESSIVE**

The image is created from the first scanline to the last without skipping any.

**D3DSCANLINEORDERING\_INTERLACED**

The image is created using the interlaced method in which odd-numbered lines are drawn on odd-numbered passes and even lines are drawn on even-numbered passes.

## Remarks

This enumeration is used as a member in [**D3DDISPLAYMODEFILTER**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddisplaymodefilter) and [**D3DDISPLAYMODEEX**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddisplaymodeex).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

