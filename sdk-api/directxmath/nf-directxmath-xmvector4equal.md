# XMVector4Equal function

## Description

Tests whether two 4D vectors are equal.

## Parameters

### `V1` [in]

4D vector.

### `V2` [in]

4D vector.

## Return value

Returns true if the 4D vectors are equal and false otherwise.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return ( V1.x == V2.x &&
         V1.y == V2.y &&
         V1.z == V2.z &&
         V1.w == V2.w );
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-comparison)

[XMVector4EqualR](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4equalr)