# D3DX11FilterTexture function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **GenerateMipMaps** and **GenerateMipMaps3D**.

Generates mipmap chain using a particular texture filter.

## Parameters

*pContext*

Type: **[**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext)\***

A pointer to an [**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext) object.

*pTexture*

Type: **[**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource)\***

The texture object to be filtered. See [**ID3D11Resource**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11resource).

*SrcLevel*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The mipmap level whose data is used to generate the rest of the mipmap chain.

*MipFilter*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags controlling how each miplevel is filtered (or D3DX11\_DEFAULT for D3DX11\_FILTER\_LINEAR). See [**D3DX11\_FILTER\_FLAG**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-filter-flag).

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

