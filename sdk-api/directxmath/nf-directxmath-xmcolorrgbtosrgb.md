# XMColorRGBToSRGB function

## Description

Converts an RGB color vector to sRGB.

## Parameters

### `rgb`

The original RGB color vector.

## Return value

Returns an **XMVECTOR** describing the converted sRGBA color vector. The x element is red, the y element is green, the z element is blue, and the w element is the alpha value (which is a copy of rgb.w). Each element value has a range of 0.0 to 1.0 in the sRGB colorspace.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)

[XMColorSRGBToRGB](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcolorsrgbtorgb)