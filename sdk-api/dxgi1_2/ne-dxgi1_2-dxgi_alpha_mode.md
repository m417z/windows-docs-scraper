# DXGI_ALPHA_MODE enumeration

## Description

Identifies the alpha value, transparency behavior, of a surface.

## Constants

### `DXGI_ALPHA_MODE_UNSPECIFIED:0`

Indicates that the transparency behavior is not specified.

### `DXGI_ALPHA_MODE_PREMULTIPLIED:1`

Indicates that the transparency behavior is premultiplied. Each color is first scaled by the alpha value. The alpha value itself is the same in both straight and premultiplied alpha. Typically, no color channel value is greater than the alpha channel value. If a color channel value in a premultiplied format is greater than the alpha channel, the standard source-over blending math results in an additive blend.

### `DXGI_ALPHA_MODE_STRAIGHT:2`

Indicates that the transparency behavior is not premultiplied. The alpha channel indicates the transparency of the color.

### `DXGI_ALPHA_MODE_IGNORE:3`

Indicates to ignore the transparency behavior.

### `DXGI_ALPHA_MODE_FORCE_DWORD:0xffffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile
to a size other than 32 bits. This value is not used.

## Remarks

For more information about alpha mode, see [D2D1_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dcommon/ne-dcommon-d2d1_alpha_mode).

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1)