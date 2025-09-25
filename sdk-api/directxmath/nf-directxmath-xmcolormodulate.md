# XMColorModulate function

## Description

Blends two colors by multiplying corresponding components together.

## Parameters

### `C1` [in]

**XMVECTOR** describing the first color.

### `C2` [in]

**XMVECTOR** describing the second color.

## Return value

Returns an **XMVECTOR** describing the color resulting from the modulation.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR colorOut;

colorOut.x = C1.x * C2.x;
colorOut.y = C1.y * C2.y;
colorOut.z = C1.z * C2.z;
colorOut.w = C1.w * C2.w;

return colorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Color Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-color)