# XMColorSRGBToRGB function

## Description

Converts an sRGB color vector to RGB.

## Parameters

### `srgb`

An sRGB color vector.

## Return value

Returns an **XMVECTOR** describing the converted RGBA color vector. The x element is red, the y element is green, the z element is blue, and the w element is the alpha value (which is a copy of srgb.w). Each element value has a range of 0.0 to 1.0 in the RGB colorspace.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorRGBToSRGB](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcolorrgbtosrgb)