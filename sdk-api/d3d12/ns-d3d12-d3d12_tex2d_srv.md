## Description

Describes the subresource from a 2D texture to use in a shader-resource view.

## Members

### `MostDetailedMip`

The index of the most detailed mipmap level to use; this number is between 0 and **MipLevels** (from the original Texture2D for which [ID3D12Device::CreateShaderResourceView](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createshaderresourceview) creates a view) -1.

### `MipLevels`

The maximum number of mipmap levels for the view of the texture. See the remarks in [D3D12_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_srv). Set to -1 to indicate all the mipmap levels from **MostDetailedMip** on down to least detailed.

### `PlaneSlice`

The index (plane slice number) of the plane to use in the texture.

### `ResourceMinLODClamp`

Specifies the minimum mipmap level that you can access. Specifying 0.0f means that you can access all of the mipmap levels. Specifying 3.0f means that you can access mipmap levels from 3.0f to *MipCount - 1*.

We recommend that you don't set *MostDetailedMip* and *ResourceMinLODClamp* at the same time. Instead, set one of those two members to 0 (to get default behavior). That's because *MipLevels* is interpreted differently in conjunction with different fields:
* For *MostDetailedMip*, mips are in the range \[*MostDetailedMip*, *MostDetailedMip* + *MipLevels* - 1].
* For *ResourceMinLODClamp*, mips are in the range \[*ResourceMinLODClamp*, *MipLevels* - 1].

## Remarks

This structure is one member of a shader-resource-view description, [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)