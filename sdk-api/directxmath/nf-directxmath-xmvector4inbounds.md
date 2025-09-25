# XMVector4InBounds function

## Description

Tests whether the components of a 4D vector are within set bounds.

## Parameters

### `V` [in]

4D vector to test.

### `Bounds` [in]

4D vector that determines the bounds.

## Return value

Returns true if all of the components of *V* are within the set bounds, and false otherwise.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return (V.x <= Bounds.x && V.x >= -Bounds.x) &&
       (V.y <= Bounds.y && V.y >= -Bounds.y) &&
       (V.z <= Bounds.z && V.z >= -Bounds.z) &&
       (V.w <= Bounds.w && V.w >= -Bounds.w);
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 4D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector4-geometric)