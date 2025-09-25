# XMVectorRound function

## Description

Rounds each component of a vector to the nearest even integer (known as "Bankers Rounding").

## Parameters

### `V` [in]

Vector whose components should be rounded.

## Return value

Returns a vector, each of whose components are rounded to the nearest integer.

## Remarks

Banker's Rounding is used because it is the native vector rounding intrinsic method for both SSE4 and ARMv8 NEON.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)