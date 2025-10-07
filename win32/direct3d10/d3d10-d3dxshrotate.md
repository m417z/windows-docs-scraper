# D3DXSHRotate function (D3DX10.h)

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [Spherical Harmonics Math](https://github.com/Microsoft/DirectXMath/tree/main/SHMath) library function **XMSHRotate**.

Rotates the spherical harmonic (SH) vector by the given matrix.

## Parameters

*pOut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to Spherical harmonic (SH) output coefficients. The evaluation generates Order² coefficients. This pointer should not alias with pIn. See Remarks.

*Order* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Order of the SH evaluation. Must be in the range of D3DXSH\_MINORDER to D3DXSH\_MAXORDER, inclusive. The evaluation generates Order² coefficients. The degree of the evaluation is Order - 1.

*pMatrix* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the rotation matrix. The rotation sub-matrix must be orthogonal, with a unit determinant.

*pIn* \[in\]

Type: **const [**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to rotated SH coefficients.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to SH output coefficients.

## Remarks

Each coefficient of the basis function Yₗₘ is stored at memory location l² + m + l, where:

- l is the degree of the basis function.
- m is the basis function index for the given l value and ranges from -l to l, inclusive.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

