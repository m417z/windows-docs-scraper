# D3DXQuaternionRotationYawPitchRoll function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a quaternion with the given yaw, pitch, and roll.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure that is the result of the operation.

*Yaw* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Yaw around the y-axis, in radians.

*Pitch* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch around the x-axis, in radians.

*Roll* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Roll around the z-axis, in radians.

## Return value

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to a [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure with the specified yaw, pitch, and roll.

## Remarks

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXQuaternionRotationYawPitchRoll** function can be used as a parameter for another function.

Use [**D3DXQuaternionNormalize**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionnormalize) for any quaternion input that is not already normalized.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXQuaternionRotationAxis**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionrotationaxis)

[**D3DXQuaternionRotationMatrix**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternionrotationmatrix)

