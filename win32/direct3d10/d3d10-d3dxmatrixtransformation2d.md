# D3DXMatrixTransformation2D function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a 2D transformation matrix that represents transformations in the xy plane. **NULL** arguments are treated as identity transformations.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure that contains the result of the transformations.

*pScalingCenter* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector2), a point identifying the scaling center. If this argument is **NULL**, an identity Msc matrix is applied to the formula in Remarks.

*ScalingRotation* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the scaling rotation factor.

*pScaling* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a D3DXVECTOR2 structure, a point identifying the scale. If this argument is **NULL**, an identity Mₛ matrix is applied to the formula in Remarks.

*pRotationCenter* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a D3DXVECTOR2 structure, a point identifying the rotation center. If this argument is **NULL**, an identity Mrc matrix is applied to the formula in Remarks.

*Rotation* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The angle of rotation in radians.

*pTranslation* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a D3DXVECTOR2 structure, identifying the translation. If this argument is **NULL**, an identity Mₜ matrix is applied to the formula in Remarks.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a D3DXMATRIX structure that contains the transformation matrix.

## Remarks

This function calculates the transformation matrix with the following formula, with matrix concatenation evaluated in left-to-right order:

Mout = (Msc)⁻¹\* (Msr)⁻¹\* Mₛ \* Msr \* Msc \* (Mrc)⁻¹\* Mr \* Mrc \* Mₜ

where:

Mout = output matrix (pOut)

Msc = scaling center matrix (pScalingCenter)

Msr = scaling rotation matrix (pScalingRotation)

Mₛ = scaling matrix (pScaling)

Mrc = center of rotation matrix (pRotationCenter)

Mr = rotation matrix (Rotation)

Mₜ = translation matrix (pTranslation)

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXMatrixTransformation2D function can be used as a parameter for another function.

For 3D transformations, use [**D3DXMatrixTransformation**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrixtransformation).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

