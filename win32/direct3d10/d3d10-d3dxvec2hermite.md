# D3DXVec2Hermite function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Performs a Hermite spline interpolation, using the specified 2D vectors.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to the [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector2) that is the result of the operation.

*pV1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*pT1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a tangent vector.

*pV2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a position vector.

*pT2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source D3DXVECTOR2 structure, a tangent vector.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weighting factor. See Remarks.

## Return value

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a D3DXVECTOR2 structure that is the result of the Hermite spline interpolation.

## Remarks

The **D3DXVec2Hermite** function interpolates from (positionA, tangentA) to (positionB, tangentB) using Hermite spline interpolation.

The spline interpolation is a generalization of the ease-in, ease-out spline. The ramp is a function of Q(s) with the following properties.

Q(s) = As³ + Bs² + Cs + D (and therefore, Q'(s) = 3As² + 2Bs + C)

a) Q(0) = v1, so Q'(0) = t1

b) Q(1) = v2, so Q'(1) = t2

v1 is the contents of pV1, v2 in the contents of pV2, t1 is the contents of pT1, and t2 is the contents of pT2.

These properties are used to solve for A, B, C, D.

```
D = v1  (from a)
C = t1  (from a)
3A + 2B = t2 - t-1 (substituting for C)
A + B = v2 - v1 - t1 (substituting for C and D)
```

Plug in the solutions for A,B,C and D to generate Q(s).

```
A = 2v1 - 2v2 + t2 + t1
B = 3v2 - 3v1 - 2t1 - t2
C = t1
D = v1
```

This yields:

Q(s) = (2v1 - 2v2 + t2 + t1)s³ + (3v2 - 3v1 - 2t1 - t2)s² + t1s + v1

Which can be rearranged as:

Q(s) = (2s³ - 3s² + 1)v1 + (-2s³ + 3s²)v2 + (s³ - 2s² + s)t1 + (s³ - s²)t2

Hermite splines are useful for controlling animation because the curve runs through all the control points. Also, because the position and tangent are explicitly specified at the ends of each segment, it is easy to create a C2 continuous curve as long as you make sure that your starting position and tangent match the ending values of the last segment.

The return value for this function is the same value returned in the pOut parameter. In this way, the **D3DXVec2Hermite** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

