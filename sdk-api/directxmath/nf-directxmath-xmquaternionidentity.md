# XMQuaternionIdentity function

## Description

Returns the identity quaternion.

## Return value

An [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) union that is the identity quaternion.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

Given a quaternion (x, y, z, w), the `XMQuaternionIdentity` function will return the quaternion (0, 0, 0, 1).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)