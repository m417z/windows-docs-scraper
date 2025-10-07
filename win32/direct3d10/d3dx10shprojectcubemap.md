# D3DX10SHProjectCubeMap function

Projects a function represented in a cube map into spherical harmonics.

## Parameters

*Order*

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Order of the SH evaluation, generates Order^2 coefs, degree is Order-1.

*pCubeMap*

Type: **[**ID3D10Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10texture2d)\***

Cubemap that is going to be projected into spherical harmonics. See [**ID3D10Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10texture2d).

*pROut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Output SH vector for red.

*pGOut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Output SH vector for green.

*pBOut*

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Output SH vector for blue.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

