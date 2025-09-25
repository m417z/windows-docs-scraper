# D3D10_TEXCUBE_ARRAY_SRV1 structure

## Description

Specifies the [subresource(s)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from an array of [cube textures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to use in a shader-resource view.

## Members

### `MostDetailedMip`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the most detailed mipmap level to use; this number is between 0 and **MipLevels**.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of mipmap levels to use.

### `First2DArrayFace`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first 2D texture to use.

### `NumCubes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of cube textures in the array.

## Remarks

This structure is one member of a shader-resource-view description (see [D3D10_SHADER_RESOURCE_VIEW_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_shader_resource_view_desc1)).

This structure requires Windows Vista Service Pack 1.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)