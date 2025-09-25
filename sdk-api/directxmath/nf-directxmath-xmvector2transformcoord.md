# XMVector2TransformCoord function

## Description

Transforms a 2D vector by a given matrix, projecting the result back into w = 1.

## Parameters

### `V` [in]

2D vector.

### `M` [in]

Transformation matrix.

## Return value

Returns the transformed vector.

## Remarks

`XMVector2TransformCoord` performs transformations by using the input matrix row 0 and row 1 for rotation and scaling,
and row 3 for translation (effectively assuming row 2 is 0). The w component of the input vector is assumed to be 1.0.
The z component of the returned vector should be ignored and its w component will have a value of 1.0.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-transformation)

[XMVector2TransformCoordStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2transformcoordstream)