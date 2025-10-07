# D3DXMatrixAffineTransformation2D function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a 2D affine transformation matrix in the xy plane. **NULL** arguments are treated as identity transformations.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*Scaling* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scaling factor.

*pRotationCenter* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure, a point identifying the center of rotation. If this argument is **NULL**, an identity Mrc matrix is applied to the formula in Remarks.

*Rotation* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The angle of rotation.

*pTranslation* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure, representing the translation. If this argument is **NULL**, an identity Mₜ matrix is applied to the formula in Remarks.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is an affine transformation matrix.

## Remarks

This function calculates the affine transformation matrix with the following formula, with matrix concatenation evaluated in left-to-right order:

Mout = Mₛ \* (Mrc)⁻¹ \* Mr \* Mrc \* Mₜ

where:

Mout = output matrix (*pOut*)

Mₛ = scaling matrix (*Scaling*)

Mrc = center of rotation matrix (*pRotationCenter*)

Mr = rotation matrix (*Rotation*)

Mₜ = translation matrix (*pTranslation*)

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXMatrixAffineTransformation2D** function can be used as a parameter for another function.

For 3D affine transformations, use [**D3DXMatrixAffineTransformation**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixaffinetransformation).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixTransformation2D**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixtransformation2d)

[Transforms (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/transforms)

