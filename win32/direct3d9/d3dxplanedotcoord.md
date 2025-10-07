# D3DXPlaneDotCoord function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Computes the dot product of a plane and a 3D vector. The w parameter of the vector is assumed to be 1.

## Parameters

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to a source [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure.

*pV* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a source [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The dot product of the plane and 3D vector.

## Remarks

Given a plane (a, b, c, d) and a 3D vector (x, y, z) the return value of this function is a\*x + b\*y + c\*z + d\*1. The **D3DXPlaneDotCoord** function is useful for determining the plane's relationship with a coordinate in 3D space.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXPlaneDot**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplanedot)

[**D3DXPlaneDotNormal**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplanedotnormal)

