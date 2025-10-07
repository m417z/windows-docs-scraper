# D3DXColorAdd function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Adds two color values together to create a new color value.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the result of the operation.

*pC1* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

*pC2* \[in\]

Type: **const [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

Pointer to a source [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure.

## Return value

Type: **[**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor)\***

This function returns a pointer to a [**D3DXCOLOR**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolor) structure that is the sum of two color values.

## Remarks

The return value for this function is the same value returned in pOut. In this way, the **D3DXColorAdd** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXColorModulate**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolormodulate)

[**D3DXColorSubtract**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcolorsubtract)

