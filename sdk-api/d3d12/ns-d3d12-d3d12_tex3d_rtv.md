# D3D12_TEX3D_RTV structure

## Description

Describes the subresources from a 3D texture to use in a render-target view.

## Members

### `MipSlice`

The index of the mipmap level to use mip slice.

### `FirstWSlice`

First depth level to use.

### `WSize`

Number of depth levels to use in the render-target view, starting from **FirstWSlice**. A value of -1 indicates all of the slices along the w axis, starting from **FirstWSlice**.

## Remarks

Use this structure with a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure to view the resource as a 3D texture.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)