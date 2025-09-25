# XMVector3TransformNormal function

## Description

Transforms the 3D vector normal by the given matrix.

## Parameters

### `V` [in]

3D normal vector.

### `M` [in]

Transformation matrix.

## Return value

Returns the transformed vector.

## Remarks

`XMVector3TransformNormal` performs transformations using the input matrix rows 0, 1, and 2 for rotation and scaling, and ignores row 3.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-transformation)

[XMVector3TransformNormalStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3transformnormalstream)