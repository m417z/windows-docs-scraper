# D3D11_TEX2D_ARRAY_DSV structure

## Description

Specifies the subresources from an array 2D textures that are accessible to a depth-stencil view.

## Members

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first mipmap level to use.

### `FirstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first texture to use in an array of textures.

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures to use.

## Remarks

This structure is one member of a depth-stencil-view description (see [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)