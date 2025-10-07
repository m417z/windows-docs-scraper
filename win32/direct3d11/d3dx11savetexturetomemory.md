# D3DX11SaveTextureToMemory function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **CaptureTexture** then **SaveToXXXMemory** (where XXX is WIC, DDS, or TGA; WIC doesn't support DDS and TGA; D3DX 9 supported TGA as a common art source format for games).

Save a texture to memory.

## Parameters

*pContext*

Type: **[**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext)\***

A pointer to an [**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext) object.

*pSrcTexture* \[in\]

Type: **[**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource)\***

Pointer to the texture to be saved. See [**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource).

*DestFormat* \[in\]

Type: **[**D3DX11\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-file-format)**

The format the texture will be saved as. See [**D3DX11\_IMAGE\_FILE\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-file-format).

*ppDestBuf* \[out\]

Type: **[**LPD3D10BLOB**](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob)\***

Address of a pointer to the memory containing the saved texture.

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional.

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

