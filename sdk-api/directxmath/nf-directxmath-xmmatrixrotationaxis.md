# XMMatrixRotationAxis function

## Description

Builds a matrix that rotates around an arbitrary axis.

## Parameters

### `Axis` [in]

Vector describing the axis of rotation.

### `Angle` [in]

Angle of rotation in radians. Angles are measured clockwise when looking along the rotation axis toward the origin.

## Return value

Returns the rotation matrix.

## Remarks

If *Axis* is a normalized vector, it is faster to use the [XMMatrixRotationNormal](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmmatrixrotationnormal) function to build this type of matrix.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)