# XMQuaternionRotationRollPitchYaw function

## Description

Computes a rotation quaternion based on the pitch, yaw, and roll (Euler angles).

## Parameters

### `Pitch` [in]

Angle of rotation around the x-axis, in radians.

### `Yaw` [in]

Angle of rotation around the y-axis, in radians.

### `Roll` [in]

Angle of rotation around the z-axis, in radians.

## Return value

Returns the rotation quaternion.

## Remarks

The DirectXMath quaternion functions use an XMVECTOR 4-vector to represent quaternions, where the X, Y, and Z components are the vector part and the W component is the scalar part.

Angles are measured clockwise when looking along the rotation axis toward the origin. This is a left-handed coordinate system. To use right-handed coordinates, negate all three angles.

The order of transformations is roll first, then pitch, then yaw. The rotations are all applied in the global coordinate frame.

> This function takes x-axis, y-axis, z-axis angles as input parameters. The assignment of the labels *pitch* to the x-axis, *yaw* to the y-axis, and *roll* to the z-axis is a common one for computer graphics and games as it matches typical 'view' coordinate systems. There are of course other ways to assign those labels when using other coordinate systems (i.e. *roll* could be the x-axis, *pitch* the y-axis, and *yaw* the z-axis).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Quaternion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-quaternion)