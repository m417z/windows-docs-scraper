# D3D12_TEX2D_ARRAY_DSV structure

## Description

Describes the subresources from an array of 2D textures that are accessible to a depth-stencil view.

## Members

### `MipSlice`

The index of the first mipmap level to use.

### `FirstArraySlice`

The index of the first texture to use in an array of textures.

### `ArraySize`

Number of textures to use.

## Remarks

Use this structure with a [D3D12_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_view_desc) structure to view the resource as an array of 2D textures.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)