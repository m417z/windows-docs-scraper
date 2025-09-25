# XMColorRGBToXYZ function

## Description

Converts RGB color values to XYZ color values.

## Parameters

### `rgb` [in]

Color value to convert. X element is Red, Y element is Green, Z element is Blue, and W element is Alpha. Each has a range of 0.0 to 1.0.

## Return value

Returns the converted color value with the tristimulus values of X, Y, and Z in the corresponding element, and the W element with Alpha (a copy of rgb.w). Each has a range of 0.0 to 1.0.

## Remarks

Uses the CIE XYZ colorspace.

**Note** `XMColorRGBToXYZ` is new for DirectXMath and is not available for XNAMath 2.x.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorXYZToRGB](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcolorxyztorgb)