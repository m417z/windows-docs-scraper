# D3DXPlaneDot function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Computes the dot product of a plane and a 4D vector.

## Parameters

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to a source [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure.

*pV* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The dot product of the plane and 4D vector.

## Remarks

Given a plane (a, b, c, d) and a 4D vector (x, y, z, w) the return value of this function is a\*x + b\*y + c\*z + d\*w. The **D3DXPlaneDot** function is useful for determining the plane's relationship with a homogeneous coordinate. For example, this function could be used to determine if a particular coordinate is on a particular plane, or on which side of a particular plane a particular coordinate lies.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXPlaneDotCoord**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplanedotcoord)

[**D3DXPlaneDotNormal**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplanedotnormal)

