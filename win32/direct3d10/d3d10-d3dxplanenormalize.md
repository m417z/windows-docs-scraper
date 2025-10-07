# D3DXPlaneNormalize function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Normalizes the plane coefficients so that the plane normal has unit length.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxplane) that is the result of the operation.

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the source D3DXPLANE structure.

## Return value

Type: **[**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to a D3DXPLANE structure that represents the normal of the plane.

## Remarks

This function normalizes a plane so that \|a,b,c\| == 1.

The return value for this function is the same value returned in the pOut parameter. In this way, this function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

