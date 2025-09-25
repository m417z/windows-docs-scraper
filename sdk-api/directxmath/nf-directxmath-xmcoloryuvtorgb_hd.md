# XMColorYUVToRGB_HD function

## Description

Converts YUV color values to RGB HD color values.

## Parameters

### `yuv` [in]

Color value to convert in Luma-Chrominance (YUV) aka YCbCr. The X element contains Luma (Y, 0.0 to 1.0), the Y element
contains Blue-difference chroma (U, -0.5 to 0.5), the Z element contains the Red-difference chroma (V, -0.5 to 0.5), and the W element contains the Alpha (0.0 to 1.0).

## Return value

The converted color value. X element is Red, Y element is Green, Z element is Blue, and W element is Alpha (a copy of yuv.w). Each has a range of 0.0 to 1.0.

## Remarks

Converts using ITU-R BT.709 W(r) = 0.2126 W(b) = 0.0722 U(max) = 0.436 V(max) = 0.615.

**Note** `XMColorYUVToRGB_HD` is new for DirectXMath and is not available for XNAMath 2.x.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorRGBToYUV_HD](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcolorrgbtoyuv_hd)