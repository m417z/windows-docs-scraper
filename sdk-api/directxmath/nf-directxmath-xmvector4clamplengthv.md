# XMVector4ClampLengthV function

## Description

Clamps the length of a 4D vector to a given range.

## Parameters

### `V` [in]

4D vector to clamp.

### `LengthMin` [in]

4D vector, all of whose components are equal to the minimum clamp length. The components must be greater-than-or-equal to zero.

### `LengthMax` [in]

4D vector, all of whose components are equal to the maximum clamp length. The components must be greater-than-or-equal to zero.

## Return value

Returns a 4D vector whose length is clamped to the specified minimum and maximum.

## Remarks

This function is identical to [XMVector4ClampLength](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4clamplength) except that *LengthMin* and *LengthMax* are supplied using 4D vectors instead of **float** values.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)

[XMVector4ClampLength](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4clamplength)