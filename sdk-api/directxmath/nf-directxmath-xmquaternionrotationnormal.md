# XMQuaternionRotationNormal function

## Description

Computes the rotation quaternion about a normal vector.

## Parameters

### `NormalAxis` [in]

Normal vector describing the axis of rotation.

### `Angle` [in]

Angle of rotation in radians. Angles are measured clockwise when looking along the rotation axis toward the origin.

## Return value

Returns the rotation quaternion.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)