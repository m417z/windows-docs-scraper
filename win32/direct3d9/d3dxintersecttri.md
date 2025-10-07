# D3DXIntersectTri function (D3DX9Mesh.h)

Computes the intersection of a ray and a triangle.

## Parameters

*p0* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, describing the first triangle vertex position.

*p1* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, describing the second triangle vertex position.

*p2* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, describing the third triangle vertex position.

*pRayPos* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, specifying the point where the ray begins.

*pRayDir* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, specifying the direction of the ray.

*pU* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Barycentric hit coordinates, U.

*pV* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Barycentric hit coordinates, V.

*pDist* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Ray-intersection parameter distance.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns **TRUE** if the ray intersects the area of the triangle. Otherwise, returns **FALSE**.

## Remarks

The [**D3DXIntersect**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxintersect) function provides a way to understand points in and around a triangle, independent of where the triangle is actually located. This function returns the resulting point by using the following equation: V1 + U(V2 - V1) + V(V3 - V1).

Any point in the plane V1V2V3 can be represented by the barycentric coordinate (U,V). The parameter U controls how much V2 gets weighted into the result, and the parameter V controls how much V3 gets weighted into the result. Lastly, the value of \[1 - (U + V)\] controls how much V1 gets weighted into the result.

Barycentric coordinates are a form of general coordinates. In this context, using barycentric coordinates represents a change in coordinate systems. What holds true for Cartesian coordinates holds true for barycentric coordinates.

Barycentric coordinates define a point inside a triangle in terms of the triangle's vertices. For a more in-depth description of barycentric coordinates, see [Mathworld's Barycentric Coordinates Description](https://mathworld.wolfram.com/BarycentricCoordinates.html).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX9Mesh.h |
| Library<br> | D3dx9.lib |

## See also

[Mesh Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-mesh)

