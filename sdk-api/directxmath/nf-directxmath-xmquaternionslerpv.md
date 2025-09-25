# XMQuaternionSlerpV function

## Description

Interpolates between two unit quaternions, using spherical linear interpolation.

## Parameters

### `Q0` [in]

Unit quaternion to interpolate from.

### `Q1` [in]

Unit quaternion to interpolate to.

### `T` [in]

Interpolation control factor. All components of this vector must be the same.

## Return value

Returns the interpolated quaternion. If *Q0* and *Q1* are not unit quaternions, the resulting
interpolation is undefined.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

This function is identical to [XMQuaternionSlerp](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionslerp) except that
*T* is supplied using a 4D vector instead of a **float** value.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionSlerp](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionslerp)