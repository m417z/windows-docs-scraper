# D3DXVec4Scale function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Scales a 4D vector.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure that is the result of the operation.

*pV* \[in\]

Type: **const [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the source [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure.

*s* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Scaling value.

## Return value

Type: **[**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4)\***

Pointer to the [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector4) structure that is the scaled vector.

## Remarks

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXVec4Scale** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXVec4Add**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvec4add)

[**D3DXVec4Subtract**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvec4subtract)

