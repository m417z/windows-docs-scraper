# D3DXVec2CatmullRom function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Performs a Catmull-Rom interpolation, using the specified 2D vectors.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to the [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector2) that is the result of the operation.

*pV0* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*pV1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*pV2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*pV3* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

## Return value

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a D3DXVECTOR2 structure that is the result of the Catmull-Rom interpolation.

## Remarks

Given four points (p1, p2, p3, p4), find a function Q(s) such that:

```
Q(s) is a cubic function.
Q(s) interpolates between p2 and p3 as s ranges from 0 to 1.
Q(s) is parallel to the line joining p1 to p3 when s is 0.
Q(s) is parallel to the line joining p2 to p4 when s is 1.
```

The Catmull-Rom spline can be derived from the Hermite spline by setting:

```
v1 = p2
v2 = p3
t1 = (p3 - p1) / 2
t2 = (p4 - p2) / 2
```

where:

v1 is the contents of pV0.

v2 is the contents of pV1.

p3 is the contents of pV2.

p4 is the contents of pV3.

Using the Hermite spline equation:

```
Q(s) = (2s3 - 3s2 + 1)v1 + (-2s3 + 3s2)v2 + (s3 - 2s2 + s)t1 + (s3 - s2)t2
```

and substituting for v1, v2, t1, t2 yields:

```
Q(s) = (2s3 - 3s2 + 1)p2 + (-2s3 + 3s2)p3 + (s3 - 2s2 + s)(p3 - p1) / 2 + (s3 - s2)(p4 - p2)/2
```

This can be rearranged as:

```
Q(s) = [(-s3 + 2s2 - s)p1 + (3s3 - 5s2 + 2)p2 + (-3s3 + 4s2 + s)p3 + (s3 - s2)p4] / 2
```

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

