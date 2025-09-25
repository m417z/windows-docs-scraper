# XMVector2GreaterOrEqual function

## Description

Tests whether one 2D vector is greater-than-or-equal-to another 2D vector.

## Parameters

### `V1` [in]

2D vector.

### `V2` [in]

2D vector.

## Return value

Returns true if *V1* is greater-than-or-equal-to *V2*, and false otherwise. See the remarks section.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return ( V1.x >= V2.x && V1.y >= V2.y );
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-comparison)

[XMVector2GreaterOrEqualR](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector2greaterorequalr)