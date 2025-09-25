# D3D12_TEX2D_ARRAY_RTV structure

## Description

Describes the subresources from an array of 2D textures to use in a render-target view.

## Members

### `MipSlice`

The index of the mipmap level to use mip slice.

### `FirstArraySlice`

The index of the first texture to use in an array of textures.

### `ArraySize`

Number of textures in the array to use in the render target view, starting from **FirstArraySlice**.

### `PlaneSlice`

The index (plane slice number) of the plane to use in an array of textures.

## Remarks

Use this structure with a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure to view the resource as an array of 2D textures.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)