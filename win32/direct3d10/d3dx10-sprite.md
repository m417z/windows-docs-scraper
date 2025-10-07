# D3DX10\_SPRITE structure

Defines position, texture, and color information about a sprite.

## Members

**matWorld**

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)**

The sprite's model-world transformation. This defines the position and orientation of the sprite in world space.

**TexCoord**

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)**

Offset from the upper-left corner of the texture indicating where the sprite image should start in the texture. **TexCoord** is in texture coordinates.

**TexSize**

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)**

A vector containing the width and height of the sprite in texture coordinates.

**ColorModulate**

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)**

A color that will be multiplied with the pixel color before rendering.

**pTexture**

Type: **[**ID3D10ShaderResourceView**](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)\***

Pointer to a shader-resource view representing the sprite's texture. See [**ID3D10ShaderResourceView Interface**](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview).

**TextureIndex**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The index of the texture. If pTexture does not represent a texture array, then this should be 0.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

