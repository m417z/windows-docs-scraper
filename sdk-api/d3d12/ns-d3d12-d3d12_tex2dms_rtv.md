# D3D12_TEX2DMS_RTV structure

## Description

Describes the subresource from a multi sampled 2D texture to use in a render-target view.

## Members

### `UnusedField_NothingToDefine`

Integer of any value. See remarks.

## Remarks

This structure is a member of the [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure.

Because a multi sampled 2D texture contains a single subresource, there is actually nothing to specify in **D3D12_TEX2DMS_RTV**. Consequently, **UnusedField_NothingToDefine** is included so that this structure will compile in C.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)