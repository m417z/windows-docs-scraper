# D3DXMatrixRotationQuaternion function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a rotation matrix from a quaternion.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*pQ* \[in\]

Type: **const [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the source [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion) structure.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure built from the source quaternion.

## Remarks

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixRotationQuaternion** function can be used as a parameter for another function.

For information about how to calculate quaternion values from a direction vector ( x, y, z ) and an angle of rotation, see [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixRotationAxis**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationaxis)

[**D3DXMatrixRotationX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationx)

[**D3DXMatrixRotationY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationy)

[**D3DXMatrixRotationYawPitchRoll**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationyawpitchroll)

[**D3DXMatrixRotationZ**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationz)

