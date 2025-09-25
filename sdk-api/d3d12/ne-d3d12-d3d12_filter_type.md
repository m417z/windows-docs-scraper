# D3D12_FILTER_TYPE enumeration

## Description

Specifies the type of magnification or minification sampler filters.

## Constants

### `D3D12_FILTER_TYPE_POINT:0`

Point filtering is used as a texture magnification or minification filter. The texel with coordinates nearest to the desired pixel value is used. The texture filter to be used between mipmap levels is nearest-point mipmap filtering. The rasterizer uses the color from the texel of the nearest mipmap texture.

### `D3D12_FILTER_TYPE_LINEAR:1`

Bilinear interpolation filtering is used as a texture magnification or minification filter. A weighted average of a 2 x 2 area of texels surrounding the desired pixel is used. The texture filter to use between mipmap levels is trilinear mipmap interpolation. The rasterizer linearly interpolates pixel color, using the texels of the two nearest mipmap textures.

## Remarks

This enum is used by the [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc) structure. Also, refer to the remarks for [D3D12_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)