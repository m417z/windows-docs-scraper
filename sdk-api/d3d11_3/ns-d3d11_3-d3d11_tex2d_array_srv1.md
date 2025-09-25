# D3D11_TEX2D_ARRAY_SRV1 structure

## Description

Describes the subresources from an array of 2D textures to use in a shader-resource view.

## Members

### `MostDetailedMip`

Index of the most detailed mipmap level to use; this number is between 0 and ( **MipLevels** (from the original Texture2D for which
[ID3D11Device3::CreateShaderResourceView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createshaderresourceview1)
creates a view) - 1).

### `MipLevels`

The maximum number of mipmap levels for the view of the texture. See the remarks in [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv).

Set to -1 to indicate all the mipmap levels from **MostDetailedMip** on down to least detailed.

### `FirstArraySlice`

The index of the first texture to use in an array of textures.

### `ArraySize`

Number of textures in the array.

### `PlaneSlice`

The index (plane slice number) of the plane to use in an array of textures.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)