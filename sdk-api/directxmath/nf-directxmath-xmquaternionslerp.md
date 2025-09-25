# XMQuaternionSlerp function

## Description

Interpolates between two unit quaternions, using spherical linear interpolation.

## Parameters

### `Q0` [in]

Unit quaternion to interpolate from.

### `Q1` [in]

Unit quaternion to interpolate to.

### `t` [in]

Interpolation control factor.

## Return value

Returns the interpolated quaternion. If *Q0* and *Q1* are not unit quaternions, the resulting
interpolation is undefined.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

When *t* is 0.0f, the function returns *Q0*. When *t* is 1.0f, the function returns
*Q1*.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionSlerpV](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionslerpv)