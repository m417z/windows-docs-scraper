# XMPlaneIntersectPlane function

## Description

Finds the intersection of two planes.

## Parameters

### `pLinePoint1` [out]

Address of a 3D vector describing one point on the line of intersection. See remarks.

### `pLinePoint2` [out]

Address of a 3D vector describing a second point on the line of intersection. See remarks.

### `P1` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `P2` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

## Return value

None.

## Remarks

If the planes are parallel to one another, all components of the returned point vectors are equal to QNaN.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)