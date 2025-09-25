# XMVector2ClampLengthV function

## Description

Clamps the length of a 2D vector to a given range.

## Parameters

### `V` [in]

2D vector to clamp.

### `LengthMin` [in]

2D vector whose x and y-components are both equal to the minimum clamp length. The x and y-components must be greater-than-or-equal to zero.

### `LengthMax` [in]

2D vector whose x and y-components are both equal to the maximum clamp length. The x and y-components must be greater-than-or-equal to zero.

## Return value

Returns a 2D vector whose length is clamped to the specified minimum and maximum.

## Remarks

This function is identical to [XMVector2ClampLength](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2clamplength) except that *LengthMin* and *LengthMax* are supplied using 2D vectors instead of **float** values.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)

[XMVector2ClampLength](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2clamplength)