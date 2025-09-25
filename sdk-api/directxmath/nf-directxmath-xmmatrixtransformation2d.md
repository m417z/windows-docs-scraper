# XMMatrixTransformation2D function

## Description

Builds a 2D transformation matrix in the xy plane.

## Parameters

### `ScalingOrigin` [in]

2D vector describing the center of the scaling.

### `ScalingOrientation` [in]

Scaling rotation factor.

### `Scaling` [in]

2D vector containing the scaling factors for the x-axis and y-axis.

### `RotationOrigin` [in]

2D vector describing the center of the rotation.

### `Rotation` [in]

Angle of rotation, in radians.

### `Translation` [in]

2D vector describing the translation.

## Return value

Returns the transformation matrix.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)