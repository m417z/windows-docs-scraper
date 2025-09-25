# D3D11_TILE_SHAPE structure

## Description

Describes the shape of a tile by specifying its dimensions.

## Members

### `WidthInTexels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width in texels of the tile.

### `HeightInTexels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height in texels of the tile.

### `DepthInTexels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth in texels of the tile.

## Remarks

Texels are equivalent to pixels. For untyped buffer resources, a texel is just a byte. For multisample antialiasing (MSAA) surfaces, the numbers are still in terms of pixels/texels.
The values here are independent of the surface dimensions. Even if the surface is smaller than what would fit in a tile, the full tile dimensions are reported here.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)