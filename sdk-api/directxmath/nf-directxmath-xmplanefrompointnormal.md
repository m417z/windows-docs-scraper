# XMPlaneFromPointNormal function

## Description

Computes the equation of a plane constructed from a point in the plane and a normal vector.

## Parameters

### `Point` [in]

3D vector describing a point in the plane.

### `Normal` [in]

3D vector normal to the plane.

## Return value

Returns a vector whose components are the coefficients of the plane (A, B, C, D) for the plane equation

```
XMVECTOR Result;

Result.x = Normal.x;
Result.y = Normal.y;
Result.z = Normal.z;
Result.w = -(Point.x * Normal.x + Point.y * Normal.y + Point.z * Normal.z);

return Result;
```

.

## Remarks

The following pseudocode demonstrates the operation of the function:

`Ax+By+Cz+D=0`

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)