# D3DXQuaternionBaryCentric function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Returns a quaternion in barycentric coordinates.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) that is the result of the operation.

*pQ1* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a source D3DXQUATERNION structure.

*pQ2* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a source D3DXQUATERNION structure.

*pQ3* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a source D3DXQUATERNION structure.

*f* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

*g* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a D3DXQUATERNION structure in Barycentric coordinates.

## Remarks

To compute the barycentric coordinates, the D3DXQuaternionBaryCentric function implements the following series of spherical linear interpolation operations:

```
Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
```

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXQuaternionBaryCentric function can be used as a parameter for another function.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternionnormalize) for any quaternion input that is not already normalized.

Barycentric coordinates define a point inside a triangle in terms of the triangle's vertices. For a more in-depth description of barycentric coordinates, see [Mathworld's Barycentric Coordinates Description](https://mathworld.wolfram.com/BarycentricCoordinates.html).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

