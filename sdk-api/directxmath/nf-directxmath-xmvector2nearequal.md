# XMVector2NearEqual function

## Description

Tests whether one 2D vector is near another 2D vector.

## Parameters

### `V1` [in]

2D vector.

### `V2` [in]

2D vector.

### `Epsilon` [in]

Tolerance value used for judging equality.

## Return value

Returns true if the difference between components is less than *Epsilon*; returns false otherwise.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return ( ( abs( V1.x - V2.x ) <= Epsilon ) &&
         ( abs( V1.y - V2.y ) <= Epsilon ) );
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-comparison)