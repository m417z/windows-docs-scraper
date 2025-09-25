# D3D12_TEX2D_RTV structure

## Description

Describes the subresource from a 2D texture to use in a render-target view.

## Members

### `MipSlice`

The index of the mipmap level to use.

### `PlaneSlice`

The index (plane slice number) of the plane to use in the texture.

## Remarks

Use this structure with a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure to view the resource as a 2D texture.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)