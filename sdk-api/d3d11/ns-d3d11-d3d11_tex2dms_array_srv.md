# D3D11_TEX2DMS_ARRAY_SRV structure

## Description

Specifies the subresources from an array of multisampled 2D textures to use in a shader-resource view.

## Members

### `FirstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first texture to use in an array of textures.

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures to use.

## Remarks

This structure is one member of a shader-resource-view description (see [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)