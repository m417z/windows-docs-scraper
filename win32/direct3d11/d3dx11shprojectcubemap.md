# D3DX11SHProjectCubeMap function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [Spherical Harmonics Math](https://github.com/Microsoft/DirectXMath/tree/master/SHMath) library function **SHProjectCubeMap**.

Projects a function represented in a cube map into spherical harmonics.

## Parameters

*pContext*

Type: **[**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext)\***

A pointer to an [**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext) object.

*Order*

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Order of the SH evaluation, generates Order^2 coefficients whose degree is Order-1. Valid range is between 2 and 6.

*pCubeMap*

Type: **[**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d)\***

A pointer to an [**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d) that represents a cubemap that is going to be projected into spherical harmonics.

*pROut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Output SH vector for red.

*pGOut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Output SH vector for green.

*pBOut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Output SH vector for blue.

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