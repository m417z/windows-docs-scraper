# XMColorAdjustSaturation function

## Description

Adjusts the saturation value of a color.

## Parameters

### `C` [in]

**XMVECTOR** describing the color. Each of the components of *C* should be in the range 0.0f to 1.0f.

### `Saturation` [in]

Saturation value. This parameter linearly interpolates between the color converted to gray-scale and the original color,
*C*. If *Saturation* is 0.0f, the function returns the gray-scale color. If
*Saturation* is 1.0f, the function returns the original color.

## Return value

Returns an **XMVECTOR** describing the color resulting from the saturation adjustment.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVector colorOut;

// Approximate values for each component's contribution to luminance.
// Based upon the NTSC standard described in ITU-R Recommendation BT.709.
float Luminance = 0.2125f * C.x + 0.7154f * C.y + 0.0721f * C.z;

colorOut.x = (C.x - Luminance) * Saturation + Luminance;
colorOut.y = (C.y - Luminance) * Saturation + Luminance;
colorOut.z = (C.z - Luminance) * Saturation + Luminance;
colorOut.w = C.w;

return colorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)