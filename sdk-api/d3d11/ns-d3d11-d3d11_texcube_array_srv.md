# D3D11_TEXCUBE_ARRAY_SRV structure

## Description

Specifies the subresources from an array of cube textures to use in a shader-resource view.

## Members

### `MostDetailedMip`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the most detailed mipmap level to use; this number is between 0 and **MipLevels** (from the original TextureCube for which [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview) creates a view) -1.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels for the view of the texture. See the remarks in [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv).

Set to -1 to indicate all the mipmap levels from **MostDetailedMip** on down to least detailed.

### `First2DArrayFace`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the first 2D texture to use.

### `NumCubes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of cube textures in the array.

## Remarks

This structure is one member of a shader-resource-view description (see [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)