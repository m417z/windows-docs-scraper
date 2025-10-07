# D3DX10LoadTextureFromTexture function

Load a texture from a texture.

## Parameters

*pSrcTexture*

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\***

Pointer to the source texture. See [**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource).

*pLoadInfo*

Type: **[**D3DX10\_TEXTURE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-texture-load-info)\***

Pointer to texture loading parameters. See [**D3DX10\_TEXTURE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-texture-load-info).

*pDstTexture*

Type: **[**ID3D10Resource**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource)\***

Pointer to the destination texture. See [**ID3D10Resource Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10resource).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

