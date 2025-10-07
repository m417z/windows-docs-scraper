# D3DXMatrixShadow function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a matrix that flattens geometry into a plane.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) structure that is the result of the operation.

*pLight* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to a [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector4) describing the light's position.

*pPlane* \[in\]

Type: **const [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplane)\***

Pointer to the source [**D3DXPLANE**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxplane).

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a D3DXMATRIX structure that flattens geometry into a plane.

## Remarks

The **D3DXMatrixShadow** function flattens geometry into a plane, as if casting a shadow from a light.

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXMatrixShadow** function can be used as a parameter for another function.

This function uses the following formula to compute the returned matrix.

```
P = normalize(Plane);
L = Light;
d = dot(P, L)

P.a * L.x + d  P.a * L.y      P.a * L.z      P.a * L.w
P.b * L.x      P.b * L.y + d  P.b * L.z      P.b * L.w
P.c * L.x      P.c * L.y      P.c * L.z + d  P.c * L.w
P.d * L.x      P.d * L.y      P.d * L.z      P.d * L.w + d
```

If the light's w-component is 0, the ray from the origin to the light represents a directional light. If it is 1, the light is a point light.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

