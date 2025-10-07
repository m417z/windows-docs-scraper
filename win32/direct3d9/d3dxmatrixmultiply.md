# D3DXMatrixMultiply function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Determines the product of two matrices.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*pM1* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure.

*pM2* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the product of two matrices.

## Remarks

The result represents the transformation M1 followed by the transformation M2 (Out = M1 \* M2).

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixMultiply** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionMultiply**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionmultiply)

