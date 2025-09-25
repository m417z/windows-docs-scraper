# XMColorAdjustContrast function

## Description

Adjusts the contrast value of a color.

## Parameters

### `C` [in]

**XMVECTOR** describing the color. Each of the components of *C* should be in the range 0.0f to 1.0f.

### `Contrast` [in]

Contrast value. This parameter linearly interpolates between 50 percent gray and the color *C*. If this
parameter is 0.0f, the returned color is 50 percent gray. If this parameter is 1.0f, the returned color is the
original color.

## Return value

Returns an **XMVECTOR** describing the color resulting from the contrast adjustment.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR colorOut;

colorOut.x = (C.x - 0.5f) * Contrast + 0.5f;
colorOut.y = (C.y - 0.5f) * Contrast + 0.5f;
colorOut.z = (C.z - 0.5f) * Contrast + 0.5f;
colorOut.w = C.w;

return colorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)