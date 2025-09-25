# XMQuaternionConjugate function

## Description

Computes the conjugate of a quaternion.

## Parameters

### `Q` [in]

The quaternion to conjugate.

## Return value

Returns the conjugate of *Q*.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

Given a quaternion (
*x*,
*y*,
*z*,
*w*), the `XMQuaternionConjugate` function returns the quaternion (-
*x*, -
*y*, -
*z*,
*w*).

Use the [XMQuaternionNormalize](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionnormalize) function for any quaternion input
that is not already normalized.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)