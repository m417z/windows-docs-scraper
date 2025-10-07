# D3DXSHProjectCubeMap function

Projects a function represented on a cube map into spherical harmonics (SH).

## Parameters

*Order* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Order of the spherical harmonic (SH) evaluation. Must be in the range of [D3DXSH\_MINORDER](https://learn.microsoft.com/windows/win32/direct3d9/other-d3dx-constants) to D3DXSH\_MAXORDER, inclusive. The evaluation generates Order² coefficients. The degree of the evaluation is Order - 1.

*pCubeMap* \[in\]

Type: **[**LPDIRECT3DCUBETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9)**

Pointer to a source cube texture. See [**IDirect3DCubeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dcubetexture9).

*pROut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the output SH vector for the red component.

*pGOut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the output SH vector for the green component.

*pBOut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the output SH vector for the blue component.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[Precomputed Radiance Transfer (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/precomputed-radiance-transfer)

