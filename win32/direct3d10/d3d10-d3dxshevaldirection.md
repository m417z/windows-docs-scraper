# D3DXSHEvalDirection function (D3DX10.h)

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [Spherical Harmonics Math](https://github.com/Microsoft/DirectXMath/tree/main/SHMath) library function **XMSHEvalDirection**.

Evaluates the spherical harmonic (SH) basis functions from an input direction vector.

## Parameters

*pOut* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to Spherical harmonic (SH) output coefficients. The evaluation generates Order² coefficients. See Remarks.

*Order* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Order of the SH evaluation. Must be in the range of D3DXSH\_MINORDER to D3DXSH\_MAXORDER, inclusive. The evaluation generates Order² coefficients. The degree of the evaluation is Order - 1.

*pDir* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

(x, y, z) direction vector in which to evaluate the SH basis functions. Must be normalized. See Remarks.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to SH output coefficients. See Remarks.

## Remarks

Each coefficient of the basis function Yₗₘ is stored at memory location l² + m + l, where:

- l is the degree of the basis function.
- m is the basis function index for the given l value and ranges from -l to l, inclusive.

On the sphere with unit radius, as shown in the following illustration, direction can be specified simply with theta, the angle about the z-axis in the right-handed direction, and phi, the angle from z.

![illustration of a sphere with unit radius](https://learn.microsoft.com/windows/win32/direct3d10/images/spherical-coordinates.png)

The following equations show the relationship between Cartesian (x, y, z) and spherical (theta, phi) coordinates on the unit sphere. The angle theta varies over the range of 0 to 2 pi, while phi varies from 0 to pi.

![equations of the relationship between cartesian and spherical coordinates](https://learn.microsoft.com/windows/win32/direct3d10/images/spherical-coordinates-equations.png)

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

