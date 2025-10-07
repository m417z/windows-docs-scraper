# D3DXQuaternionIsIdentity function

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Determines if a quaternion is an identity quaternion.

## Parameters

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that will be tested for identity.

## Return value

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the quaternion is an identity quaternion, this function returns **TRUE**. Otherwise, this function returns **FALSE**.

## Remarks

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionIdentity**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionidentity)

