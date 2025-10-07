# D3DXMatrixDecompose function (D3DX10Math.h)

> [!Note]
> The D3DX utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Breaks down a general 3D transformation matrix into its scalar, rotational, and translational components.

## Parameters

*pOutScale* \[in\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the output [**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector3) that contains scaling factors applied along the x, y, and z-axes.

*pOutRotation* \[in\]

Type: **[**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxquaternion)\***

Pointer to the [**D3DXQUATERNION**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxquaternion) that describes the rotation.

*pOutTranslation* \[in\]

Type: **[**D3DXVECTOR3**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxvector3)\***

Pointer to the D3DXVECTOR3 vector that describes the translation.

*pM* \[in\]

Type: **const [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxmatrix)\***

Pointer to an input [**D3DXMATRIX**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxmatrix) matrix to decompose.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |
| Library<br> | D3DX10.lib |

## See also

[Math Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-math)

