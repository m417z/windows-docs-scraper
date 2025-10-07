# D3DXFillVolumeTextureTX function

Uses a compiled high-level shader language (HLSL) function to fill each texel of each mipmap level of a texture.

## Parameters

*pTexture* \[in\]

Type: **[**LPDIRECT3DVOLUMETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)**

Pointer to an [**IDirect3DVolumeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9) object, representing the texture to be filled.

*pTextureShader* \[in\]

Type: **[**LPD3DXTEXTURESHADER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader)**

Pointer to a [**ID3DXTextureShader**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader) texture shader object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following:D3DERR\_NOTAVAILABLE, D3DERR\_INVALIDCALL.

## Remarks

The texture target must be an HLSL function that takes contains the following semantics:

- One input parameter must use a POSITION semantic.
- One input parameter must use a PSIZE semantic.
- The function must return a parameter that uses the COLOR semantic.

The input parameters can be in any order. For an example, see [**D3DXFillTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfilltexturetx)

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

[**D3DXFillTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfilltexturetx)

[**D3DXFillCubeTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfillcubetexturetx)

