# D3DXQuaternionLengthSq function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Returns the square of the length of a quaternion.

## Parameters

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure.

## Return value

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The quaternion's squared length.

## Remarks

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionLength**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionlength)

