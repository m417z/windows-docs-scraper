# D3DXMatrixRotationYawPitchRoll function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a matrix with a specified yaw, pitch, and roll.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

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

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure with the specified yaw, pitch, and roll.

## Remarks

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixRotationYawPitchRoll** function can be used as a parameter for another function.

The order of transformations is roll first, then pitch, then yaw. Relative to the object's local coordinate axis, this is equivalent to rotation around the z-axis, followed by rotation around the x-axis, followed by rotation around the y-axis, as shown in the following illustration.

![illustration of roll, pitch, and yaw as rotations around the three axes](https://learn.microsoft.com/windows/win32/direct3d9/images/pitchyawroll.png)

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixRotationAxis**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationaxis)

[**D3DXMatrixRotationQuaternion**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationquaternion)

[**D3DXMatrixRotationX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationx)

[**D3DXMatrixRotationY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationy)

[**D3DXMatrixRotationZ**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationz)

