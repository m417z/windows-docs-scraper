# D3DXVec3TransformCoord function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Transforms a 3D vector by a given matrix, projecting the result back into w = 1.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) that is the result of the operation.

*pV* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the source D3DXVECTOR3 structure.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure.

## Return value

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a D3DXVECTOR3 structure that is the transformed vector.

## Remarks

This function transforms the vector, pV (x, y, z, 1), by the matrix, pM, projecting the result back into w=1.

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXVec3TransformCoord function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

