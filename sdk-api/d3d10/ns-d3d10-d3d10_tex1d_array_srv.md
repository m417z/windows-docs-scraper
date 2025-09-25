# D3D10_TEX1D_ARRAY_SRV structure

## Description

Specifies the [subresource(s)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from an array of [1D textures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to use in a shader-resource view.

## Members

### `MostDetailedMip`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the most detailed mipmap level to use; this number is between 0 and **MipLevels** -1.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of subtextures to access.

### `FirstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first texture to use in an array of textures (see [array slice](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types))

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures in the array.

## Remarks

This structure is one member of a shader-resource-view description (see [D3D10_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_shader_resource_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)