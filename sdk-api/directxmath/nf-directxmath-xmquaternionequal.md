# XMQuaternionEqual function

## Description

Tests whether two quaternions are equal.

## Parameters

### `Q1` [in]

First quaternion to test.

### `Q2` [in]

Second quaternion to test.

## Return value

Returns true if the quaternions are equal and false otherwise.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)