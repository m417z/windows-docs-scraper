# XMScalarNearEqual function

## Description

Determines if two floating-point values are nearly equal.

## Parameters

### `S1` [in]

First floating-point value to compare.

### `S2` [in]

Second floating-point value to compare.

### `Epsilon` [in]

Tolerance to use when comparing *S1* and *S2*.

## Return value

Returns true if the absolute value of the difference between *S1* and *S2* is less than or equal to *Epsilon*. Returns false otherwise.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Scalar Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-scalar)