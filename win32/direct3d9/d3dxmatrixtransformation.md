# D3DXMatrixTransformation function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a transformation matrix. **NULL** arguments are treated as identity transformations.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*pScalingCenter* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, identifying the scaling center point. If this argument is **NULL**, an identity Msc matrix is applied to the formula in Remarks.

*pScalingRotation* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that specifies the scaling rotation. If this argument is **NULL**, an identity Msr matrix is applied to the formula in Remarks.

*pScaling* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, the scaling vector. If this argument is **NULL**, an identity Mₛ matrix is applied to the formula in Remarks.

*pRotationCenter* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, a point that identifies the center of rotation. If this argument is **NULL**, an identity Mrc matrix is applied to the formula in Remarks.

*pRotation* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that specifies the rotation. If this argument is **NULL**, an identity Mr matrix is applied to the formula in Remarks.

*pTranslation* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, representing the translation. If this argument is **NULL**, an identity Mₜ matrix is applied to the formula in Remarks.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the transformation matrix.

## Remarks

This function calculates the transformation matrix with the following formula, with matrix concatenation evaluated in left-to-right order:

Mout = (Msc)⁻¹ \* (Msr)⁻¹\* Mₛ \* Msr \* Msc \* (Mrc)⁻¹\* Mr \* Mrc \* Mt

where:

Mout = output matrix (*pOut*)

Msc = scaling center matrix (*pScalingCenter*)

Msr = scaling rotation matrix (*pScalingRotation*)

Mₛ = scaling matrix (*pScaling*)

Mrc = center of rotation matrix (*pRotationCenter*)

Mr = rotation matrix (*pRotation*)

Mₜ = translation matrix (*pTranslation*)

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixTransformation** function can be used as a parameter for another function.

For 2D transformations, use [**D3DXMatrixTransformation2D**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixtransformation2d).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixAffineTransformation**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixaffinetransformation)

[Transforms (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/transforms)

