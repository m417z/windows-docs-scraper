# D3DXVec3Transform function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Transforms vector (x, y, z, 1) by a given matrix.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure that is the result of the operation.

*pV* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the source [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure.

## Return value

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure that is the transformed vector.

## Remarks

This function transforms the vector, *pV* (x, y, z, 1), by the matrix *pM*.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXVec3Transform** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

