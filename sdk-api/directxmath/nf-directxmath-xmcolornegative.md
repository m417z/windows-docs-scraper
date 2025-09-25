# XMColorNegative function

## Description

Determines the negative RGB color value of a color.

## Parameters

### `C` [in]

**XMVECTOR** describing the color. Each of the components of *C* should be in the range 0.0f to 1.0f.

## Return value

Returns an **XMVECTOR** describing the negative color. The w-component (alpha) is copied unmodified from the input vector.

## Remarks

The following pseudocode shows you the operation of the function.

```
XMVECTOR colorOut;

colorOut.x = 1.0f - C.x;
colorOut.y = 1.0f - C.y;
colorOut.z = 1.0f - C.z;
colorOut.w = C.w;

return colorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)