# D3D10_FILTER_TYPE enumeration

## Description

Types of magnification or minification sampler filters.

## Constants

### `D3D10_FILTER_TYPE_POINT:0`

Point filtering used as a texture magnification or minification filter. The texel with coordinates nearest to the desired pixel value is used. The texture filter to be used between mipmap levels is nearest-point mipmap filtering. The rasterizer uses the color from the texel of the nearest mipmap texture.

### `D3D10_FILTER_TYPE_LINEAR:1`

Bilinear interpolation filtering used as a texture magnification or minification filter. A weighted average of a 2 x 2 area of texels surrounding the desired pixel is used. The texture filter to use between mipmap levels is trilinear mipmap interpolation. The rasterizer linearly interpolates pixel color, using the texels of the two nearest mipmap textures.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)