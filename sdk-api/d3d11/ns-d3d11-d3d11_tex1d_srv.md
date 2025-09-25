# D3D11_TEX1D_SRV structure

## Description

Specifies the subresource from a 1D texture to use in a shader-resource view.

## Members

### `MostDetailedMip`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the most detailed mipmap level to use; this number is between 0 and **MipLevels** (from the original Texture1D for which [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview) creates a view) -1.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels for the view of the texture. See the remarks.

Set to -1 to indicate all the mipmap levels from **MostDetailedMip** on down to least detailed.

## Remarks

This structure is one member of a shader-resource-view description (see [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc)).

As an example, assuming **MostDetailedMip** = 6 and **MipLevels** = 2, the view will have access to 2 mipmap levels, 6 and 7, of the original texture for which [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview) creates the view. In this situation, **MostDetailedMip** is greater than the **MipLevels** in the view. However, **MostDetailedMip** is not greater than the **MipLevels** in the original resource.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)