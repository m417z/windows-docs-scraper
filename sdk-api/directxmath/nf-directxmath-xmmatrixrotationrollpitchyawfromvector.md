# XMMatrixRotationRollPitchYawFromVector function

## Description

Builds a rotation matrix based on a vector containing the Euler angles (pitch, yaw, and roll).

## Parameters

### `Angles` [in]

3D vector containing the Euler angles in the order x-axis (pitch), then y-axis (yaw), and then z-axis (roll). The W element is ignored.

## Return value

Returns the rotation matrix.

## Remarks

Angles are measured clockwise when looking along the rotation axis toward the origin. This is a left-handed coordinate system. To use right-handed coordinates, negate all three angles.

The order of transformations is roll first, then pitch, and then yaw. The rotations are all applied in the global coordinate frame.

> [!NOTE]
> This function takes x-axis, y-axis, and z-axis angles as input parameters. The assignment of the labels *pitch* to the x-axis, *yaw* to the y-axis, and *roll* to the z-axis is a common one for computer graphics and games, since it matches typical 'view' coordinate systems. There are of course other ways to assign those labels when using other coordinate systems (for example, *roll* could be the x-axis, *pitch* the y-axis, and *yaw* the z-axis).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)