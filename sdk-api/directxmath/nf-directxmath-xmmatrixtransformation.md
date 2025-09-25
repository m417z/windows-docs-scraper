# XMMatrixTransformation function

## Description

Builds a transformation matrix.

## Parameters

### `ScalingOrigin` [in]

3D vector describing the center of the scaling.

### `ScalingOrientationQuaternion` [in]

Quaternion describing the orientation of the scaling.

### `Scaling` [in]

3D vector containing the scaling factors for the x-axis, y-axis, and z-axis.

### `RotationOrigin` [in]

3D vector describing the center of the rotation.

### `RotationQuaternion` [in]

Quaternion describing the rotation around the origin indicated by *RotationOrigin*.

### `Translation` [in]

3D vector describing the translations along the x-axis, y-axis, and z-axis.

## Return value

Returns the transformation matrix.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)