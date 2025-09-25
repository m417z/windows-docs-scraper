# XMPlaneIntersectLine function

## Description

Finds the intersection between a plane and a line.

## Parameters

### `P` [in]

**XMVECTOR** describing the plane coefficients (A, B, C, D) for the plane equation `Ax+By+Cz+D=0`.

### `LinePoint1` [in]

3D vector describing the first point on the line.

### `LinePoint2` [in]

3D vector describing the second point on the line.

## Return value

Returns the intersection of the plane *P* and the line defined by *LinePoint1* and
*LinePoint2*. If the line is parallel to the plane, all components of the returned vector are equal to
QNaN.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Plane Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-plane)