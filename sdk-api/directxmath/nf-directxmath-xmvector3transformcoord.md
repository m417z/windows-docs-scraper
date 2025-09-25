# XMVector3TransformCoord function

## Description

Transforms a 3D vector by a given matrix, projecting the result back into w = 1.

## Parameters

### `V` [in]

3D vector.

### `M` [in]

Transformation matrix.

## Return value

Returns the transformed vector.

## Remarks

`XMVector3TransformCoord` ignores the w component of the input vector, and uses a value of 1.0 instead. The w component of the returned vector will always be 1.0.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-transformation)

[XMVector3TransformCoordStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3transformcoordstream)