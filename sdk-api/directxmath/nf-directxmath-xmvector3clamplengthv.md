# XMVector3ClampLengthV function

## Description

Clamps the length of a 3D vector to a given range.

## Parameters

### `V` [in]

3D vector to clamp.

### `LengthMin` [in]

3D vector whose x, y, and z-components are equal to the minimum clamp length. The x, y, and z-components must be greater-than-or-equal to zero.

### `LengthMax` [in]

3D vector whose x, y, and z-components are equal to the minimum clamp length. The x, y, and z-components must be greater-than-or-equal to zero.

## Return value

Returns a 3D vector whose length is clamped to the specified minimum and maximum.

## Remarks

This function is identical to [XMVector3ClampLength](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmvector3clamplength) except that *LengthMin* and *LengthMax* are supplied using 3D vectors instead of **float** values.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-geometric)

[XMVector3ClampLength](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmvector3clamplength)