# XMVector4NearEqual function

## Description

Tests whether one 4D vector is near another 4D vector.

## Parameters

### `V1` [in]

4D vector.

### `V2` [in]

4D vector.

### `Epsilon` [in]

Tolerance value used for judging equality.

## Return value

Returns true if *V1* is near *V2* and false otherwise.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return ( ( abs( V1.x - V2.x ) <= Epsilon ) &&
         ( abs( V1.y - V2.y ) <= Epsilon ) &&
         ( abs( V1.z - V2.z ) <= Epsilon ) &&
         ( abs( V1.w - V2.w ) <= Epsilon ));
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-comparison)