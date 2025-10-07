# D3DXSphereBoundProbe function (D3DX10math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Determines if a ray intersects the volume of a sphere's bounding box.

## Parameters

*pCenter* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) structure, specifying the center coordinate of the sphere.

*Radius* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Radius of the sphere.

*pRayPosition* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) structure, specifying the origin coordinate of the ray.

*pRayDirection* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) structure, specifying the direction of the ray. This vector should not be (0,0,0) but does not need to be normalized.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns **TRUE** if the ray intersects the volume of the sphere's bounding box. Otherwise, returns **FALSE**.

## Remarks

**D3DXSphereBoundProbe** determines if the ray intersects the volume of the sphere's bounding box, not just the surface of the sphere.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10math.h |
| Library<br> | D3DX10.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-mesh)

