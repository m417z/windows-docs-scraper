# D3D12_TEX2DMS_DSV structure

## Description

Describes the subresource from a multi sampled 2D texture that is accessible to a depth-stencil view.

## Members

### `UnusedField_NothingToDefine`

Unused.

## Remarks

This structure is a member of the [D3D12_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_view_desc) structure.

Because a multi sampled 2D texture contains a single subresource, there is nothing to specify in **D3D12_TEX2DMS_DSV**. Consequently, **UnusedField_NothingToDefine** is included so that this structure will compile in C.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)