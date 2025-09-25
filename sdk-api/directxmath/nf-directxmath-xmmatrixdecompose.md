# XMMatrixDecompose function

## Description

Breaks down a general 3D transformation matrix into its scalar, rotational, and translational components.

## Parameters

### `outScale` [in, out]

Pointer to the output [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) that contains scaling factors applied along the
x, y, and z-axes.

### `outRotQuat` [in, out]

Pointer to the [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) quaternion that describes the rotation.

### `outTrans` [in, out]

Pointer to the [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) vector that describes a translation along the
x, y, and z-axes.

### `M` [in]

Pointer to an input [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) matrix to decompose.

## Return value

If the function succeeds, the return value is true. If the function fails, the return value is false.

## Remarks

**XMMatrixDecompose** provides the same basic functionality found in both [D3DXMatrixDecompose (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/d3dxmatrixdecompose) and [D3DXMatrixDecompose (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-d3dxmatrixdecompose).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)