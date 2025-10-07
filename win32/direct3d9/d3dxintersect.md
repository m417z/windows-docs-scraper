# D3DXIntersect function

Determines if a ray intersects with a mesh.

## Parameters

*pMesh* \[in\]

Type: **[**LPD3DXBASEMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh)**

Pointer to an [**ID3DXBaseMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbasemesh) interface, representing the mesh to be tested.

*pRayPos* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, specifying the point where the ray begins.

*pRayDir* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3) structure, specifying the direction of the ray.

*pHit* \[out\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a BOOL. If the ray intersects a triangular face on the mesh, this value will be set to **TRUE**. Otherwise, this value is set to **FALSE**.

*pFaceIndex* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to an index value of the face closest to the ray origin, if pHit is **TRUE**.

*pU* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a barycentric hit coordinate, U.

*pV* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a barycentric hit coordinate, V.

*pDist* \[out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a ray intersection parameter distance.

*ppAllHits* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) object, containing an array of [**D3DXINTERSECTINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxintersectinfo) structures.

*pCountOfHits* \[out\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a DWORD that contains the number of entries in the ppAllHits array.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be: E\_OUTOFMEMORY.

## Remarks

The **D3DXIntersect** function provides a way to understand points in and around a triangle, independent of where the triangle is actually located. This function returns the resulting point by using the following equation: V1 + U(V2 - V1) + V(V3 - V1).

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

