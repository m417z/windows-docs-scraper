# XMVector3Less function

## Description

Tests whether one 3D vector is less than another 3D vector.

## Parameters

### `V1` [in]

3D vector.

### `V2` [in]

3D vector.

## Return value

Returns true if *V1* is less than *V2* and false otherwise. See the remarks section.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
return ( V1.x < V2.x && V1.y < V2.y &&
         V1.z < V2.z );
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Comparison Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-comparison)