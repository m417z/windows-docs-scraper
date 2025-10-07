# D3DX11LoadTextureFromTexture function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **Resize**, **Convert**, **Compress**, **Decompress**, and/or **CopyRectangle**.

Load a texture from a texture.

## Parameters

*pContext*

Type: **[**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext)\***

A pointer to an [**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext) object.

*pSrcTexture*

Type: **[**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource)\***

Pointer to the source texture. See [**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource).

*pLoadInfo*

Type: **[**D3DX11\_TEXTURE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-texture-load-info)\***

Pointer to texture loading parameters. See [**D3DX11\_TEXTURE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-texture-load-info).

*pDstTexture*

Type: **[**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource)\***

Pointer to the destination texture. See [**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

