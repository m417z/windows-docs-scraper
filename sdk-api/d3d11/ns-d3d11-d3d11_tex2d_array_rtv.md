# D3D11_TEX2D_ARRAY_RTV structure

## Description

Specifies the subresources from an array of 2D textures to use in a render-target view.

## Members

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use mip slice.

### `FirstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first texture to use in an array of textures.

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures in the array to use in the render target view, starting from **FirstArraySlice**.

## Remarks

This structure is one member of a render-target-view description (see [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)