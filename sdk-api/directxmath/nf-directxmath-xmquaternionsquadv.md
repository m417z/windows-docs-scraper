# XMQuaternionSquadV function

## Description

Interpolates between four unit quaternions, using spherical quadrangle interpolation.

## Parameters

### `Q0` [in]

First unit quaternion.

### `Q1` [in]

Second unit quaternion.

### `Q2` [in]

Third unit quaternion.

### `Q3` [in]

Fourth unit quaternion.

### `T` [in]

Interpolation control factor. All components of this vector must be the same.

## Return value

Returns the interpolated quaternion. If *Q0*, *Q1*, *Q2*, and *Q3* are not unit
quaternions, the resulting interpolation is undefined.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions,
where the X, Y, and Z components are the vector part and the W component is the scalar part.

This function is identical to [XMQuaternionSquad](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquad) except that
*T* is supplied using a 4D vector instead of a **float** value.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)

[XMQuaternionSquad](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquad)

[XMQuaternionSquadSetup](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmquaternionsquadsetup)