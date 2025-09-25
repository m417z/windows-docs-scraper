# D3D11_TEX2D_ARRAY_RTV1 structure

## Description

Describes the subresources from an array of 2D textures to use in a render-target view.

## Members

### `MipSlice`

The index of the mipmap level to use mip slice.

### `FirstArraySlice`

The index of the first texture to use in an array of textures.

### `ArraySize`

Number of textures in the array to use in the render-target view, starting from **FirstArraySlice**.

### `PlaneSlice`

The index (plane slice number) of the plane to use in an array of textures.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)