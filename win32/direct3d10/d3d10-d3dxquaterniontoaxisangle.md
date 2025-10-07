# D3DXQuaternionToAxisAngle function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Computes a quaternion's axis and angle of rotation.

## Parameters

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion).

*pAxis* \[in, out\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

This function returns a pointer to a [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) that identifies the quaternion's axis of rotation.

*pAngle* \[in, out\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

This function returns a pointer to a FLOAT value that identifies the quaternion's angle of rotation in radians.

## Return value

No return value.

## Remarks

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

