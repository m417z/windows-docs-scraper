# XMPlaneFromPoints function

## Description

Computes the equation of a plane constructed from three points in the plane.

## Parameters

### `Point1` [in]

3D vector describing a point in the plane.

### `Point2` [in]

3D vector describing a point in the plane.

### `Point3` [in]

3D vector describing a point in the plane.

## Return value

Returns a vector whose components are the coefficients of the plane (A, B, C, D) for the plane equation

```
XMVECTOR Result;
XMVECTOR N;
XMVECTOR D;

XMVECTOR V21 = XMVectorSubtract(Point1, Point2);
XMVECTOR V31 = XMVectorSubtract(Point1, Point3);

N = XMVector3Cross(V21, V31);
N = XMVector3Normalize(N);

D = XMPlaneDotNormal(N, Point1);

Result.x = N.x;
Result.y = N.y;
Result.z = N.z;
Result.w = -D.w;

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