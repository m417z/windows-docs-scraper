# D3DXVec2BaryCentric function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Returns a point in Barycentric coordinates, using the specified 2D vectors.

## Parameters

*pOut* \[out\]

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to the [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure that is the result of the operation.

*pV1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*pV2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*pV3* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*f* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

*g* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

## Return value

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure in Barycentric coordinates.

## Remarks

The **D3DXVec2BaryCentric** function provides a way to understand points in and around a triangle, independent of where the triangle is actually located. This function returns the resulting point by using the following equation: V1 + f(V2-V1) + g(V3-V1).

Any point in the plane V1V2V3 can be represented by the Barycentric coordinate (f,g).The parameter *f* controls how much V2 gets weighted into the result, and the parameter *g* controls how much V3 gets weighted into the result. Lastly, 1-f-g controls how much V1 gets weighted into the result.

Note the following relations.

- If (f>=0 &, & g>=0 &, & 1-f-g>=0), the point is inside the triangle V1V2V3.
- If (f==0 &, & g>=0 &, & 1-f-g>=0), the point is on the line V1V3.
- If (f>=0 &, & g==0 &, & 1-f-g>=0), the point is on the line V1V2.
- If (f>=0 &, & g>=0 &, & 1-f-g==0), the point is on the line V2V3.

Barycentric coordinates are a form of general coordinates. In this context, using Barycentric coordinates represents a change in coordinate systems. What holds true for Cartesian coordinates holds true for Barycentric coordinates.

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXVec2BaryCentric** function can be used as a parameter for another function.

Barycentric coordinates define a point inside a triangle in terms of the triangle's vertices. For a more in-depth description of barycentric coordinates, see [Mathworld's Barycentric Coordinates Description](https://mathworld.wolfram.com/BarycentricCoordinates.html). (This resource may not be available in some languages and countries.)

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

