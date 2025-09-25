# D3D12_TEX2DMS_SRV structure

## Description

Describes the subresources from a multi sampled 2D texture to use in a shader-resource view.

## Members

### `UnusedField_NothingToDefine`

Integer of any value. See remarks.

## Remarks

This structure is a member of the [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc) structure.

Since a multi sampled 2D texture contains a single subresource, there is actually nothing to specify in **D3D12_TEX2DMS_SRV**. Consequently, **UnusedField_NothingToDefine** is included so that this structure will compile in C.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)