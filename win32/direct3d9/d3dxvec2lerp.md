# D3DXVec2Lerp function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Performs a linear interpolation between two 2D vectors.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to the [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure that is the result of the operation.

*pV1* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*pV2* \[in\]

Type: **const [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a source [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Parameter that linearly interpolates between the vectors.

## Return value

Type: **[**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2)\***

Pointer to a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector2) structure that is the result of the linear interpolation.

## Remarks

This function performs the linear interpolation based on the following formula: V1 + s(V2-V1).

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXVec2Lerp** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

