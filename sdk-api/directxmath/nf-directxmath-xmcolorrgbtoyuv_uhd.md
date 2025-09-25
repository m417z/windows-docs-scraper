# XMColorRGBToYUV_UHD function

## Description

Converts RGB color values to YUV UHD color values.

## Parameters

### `rgb` [in]

Color value to convert. X element is Red, Y element is Green, Z element is Blue, and W element is Alpha. Each has a range of 0.0 to 1.0.

## Return value

 Returns the converted color value in Luma-Chrominance (YUV) aka YCbCr. The X element contains Luma (Y, 0.0 to 1.0), the Y element contains
Blue-difference chroma (-0.5 to 0.5), the Z element contains the Red-difference chroma (-0.5 to 0.5), and the W element contains the Alpha (a copy of rgb.w).

## Remarks

 Converts using ITU-R BT.2020 W(r) = 0.2627 W(b) = 0.0-593 U(max) = 0.4351 V(max) = 0.6150.

> This function is new to DirectXMath 3.16

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorYUVToRGB_UHD](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcoloryuvtorgb_uhd)