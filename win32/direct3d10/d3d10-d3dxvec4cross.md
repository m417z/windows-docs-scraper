# D3DXVec4Cross function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Determines the cross-product in four dimensions.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector4) that is the result of the operation.

*pV1* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a source D3DXVECTOR4 structure.

*pV2* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a source D3DXVECTOR4 structure.

*pV3* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a source D3DXVECTOR4 structure.

## Return value

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a D3DXVECTOR4 structure that is the cross product.

## Remarks

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXVec4Cross function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

