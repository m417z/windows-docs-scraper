# D3DXVec2TransformArray function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Transforms an array (x, y, 0, 1) by a given matrix.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector4) structure that is the result of the operation.

*OutStride* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Stride between vectors in the output data stream.

*pV* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to the source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector2).

*VStride* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Stride between vectors in the input data stream.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the source [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure.

*n* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of elements in the array.

## Return value

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a D3DXVECTOR4 structure that is the transformed array.

## Remarks

This function transforms the array pV (x, y, 0, 1) by the matrix pM.

The return value for this function is the same value returned in the pOut parameter. In this way, the [**D3DXVec2Transform**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvec2transform) function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

