# XMPlaneNotEqual function

## Description

Determines if two planes are unequal.

## Parameters

### `P1` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation

```
return (P1.x != P2.x || P1.y != P2.y || P1.z != P2.z || P1.w != P2.w);
```

.

### `P2` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Return value

Returns true if the two planes are unequal and false otherwise.

## Remarks

The following pseudocode demonstrates the operation of the function.

`Ax+By+Cz+D=0`

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)