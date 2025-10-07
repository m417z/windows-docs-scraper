# D3DXQuaternionRotationAxis function (D3DX10Math.h)

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Rotates a quaternion about an arbitrary axis.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) that is the result of the operation.

*pV* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) that identifies the axis about which to rotate the quaternion.

*Angle* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Angle of rotation, in radians. Angles are measured clockwise when looking along the rotation axis toward the origin.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a D3DXQUATERNION structure rotated around the specified axis.

## Remarks

The return value for this function is the same value returned in the pOut parameter. In this way, the D3DXQuaternionRotationAxis function can be used as a parameter for another function.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

