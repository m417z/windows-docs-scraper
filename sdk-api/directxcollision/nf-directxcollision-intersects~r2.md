# Intersects(XMVECTOR, XMVECTOR, XMVECTOR, XMVECTOR)

## Description

Tests whether a triangle and a plane intersect.

## Parameters

### `V0`

A vector defining a triangle.

### `V1`

A vector defining a triangle.

### `V2`

A vector defining a triangle.

### `Plane`

A vector defining a plane.

## Return value

A **PlaneIntersectionType** value indicating whether the triangle intersects the plane.

## Remarks

**Note** `TriangleTests::Intersects` is new for DirectXMath. This functionality is not available in XNAMath 2.x.
Similar functionality for XNAMath can be found in the DirectX SDK Collision sample.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8.
Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Triangle Test Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-triangletests)