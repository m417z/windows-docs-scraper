# D3DXPlaneIntersectLine function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Finds the intersection between a plane and a line.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, identifying the intersection between the specified plane and line.

*pP* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the source [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane) structure.

*pV1* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a source [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, defining a line starting point.

*pV2* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a source [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, defining a line ending point.

## Return value

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure that is the intersection between the specified plane and line.

## Remarks

If the line is parallel to the plane, **NULL** is returned.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXPlaneIntersectLine** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

