# D3DXMatrixRotationAxis function (D3dx9math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Builds a matrix that rotates around an arbitrary axis.

## Parameters

*pOut* \[in, out\]

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to the [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure that is the result of the operation.

*pV* \[in\]

Type: **const [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the arbitrary axis. See [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3).

*Angle* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Angle of rotation in radians. Angles are measured clockwise when looking along the rotation axis toward the origin.

## Return value

Type: **[**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to a [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix) structure rotated around the specified axis.

## Remarks

The return value for this function is the same value returned in the *pOut* parameter. In this way, the **D3DXMatrixRotationAxis** function can be used as a parameter for another function.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9math.h |
| Library<br> | D3dx9.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-math)

[**D3DXMatrixRotationQuaternion**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationquaternion)

[**D3DXMatrixRotationX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationx)

[**D3DXMatrixRotationY**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationy)

[**D3DXMatrixRotationYawPitchRoll**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationyawpitchroll)

[**D3DXMatrixRotationZ**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrixrotationz)

