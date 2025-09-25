# D3D11_TEX3D_RTV structure

## Description

Specifies the subresources from a 3D texture to use in a render-target view.

## Members

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use mip slice.

### `FirstWSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

First depth level to use.

### `WSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of depth levels to use in the render-target view, starting from **FirstWSlice**. A value of -1 indicates all of the slices along the w axis, starting from **FirstWSlice**.

## Remarks

This structure is one member of a render target view. See [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)