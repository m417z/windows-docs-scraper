# XMColorYUVToRGB_UHD function

## Description

Converts YUV color values to RGB UHD color values.

## Parameters

### `yuv` [in]

Color value to convert in Luma-Chrominance (YUV) aka YCbCr. The X element contains Luma (Y, 0.0 to 1.0), the Y element
contains Blue-difference chroma (U, -0.5 to 0.5), the Z element contains the Red-difference chroma (V, -0.5 to 0.5), and the W element contains the Alpha (0.0 to 1.0).

## Return value

The converted color value. X element is Red, Y element is Green, Z element is Blue, and W element is Alpha (a copy of yuv.w). Each has a range of 0.0 to 1.0.

## Remarks

 Converts using ITU-R BT.2020 W(r) = 0.2627 W(b) = 0.0-593 U(max) = 0.4351 V(max) = 0.6150.

> This function is new to DirectXMath 3.16

### Platform Requirements

Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorRGBToYUV_UHD](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcolorrgbtoyuv_uhd)