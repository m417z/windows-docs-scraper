# XMVector2TransformNormal function

## Description

Transforms the 2D vector normal by the given matrix.

## Parameters

### `V` [in]

2D normal vector.

### `M` [in]

Transformation matrix.

## Return value

Returns the transformed vector.

## Remarks

`XMVector2TransformNormal` uses row 0 and 1 of the input transformation matrix for rotation and scaling. Rows 2 and 3 are ignored.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-transformation)

[XMVector2TransformNormalStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2transformnormalstream)