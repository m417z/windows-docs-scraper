# ContainedBy function

## Description

Tests whether a triangle is contained within six planes (typically a frustum).

## Parameters

### `V0`

A vector defining the triangle.

### `V1`

A vector defining the triangle.

### `V2`

A vector defining the triangle.

### `Plane0`

A vector defining a plane.

### `Plane1`

A vector defining a plane.

### `Plane2`

A vector defining a plane.

### `Plane3`

A vector defining a plane.

### `Plane4`

A vector defining a plane.

### `Plane5`

A vector defining a plane.

## Return value

A [ContainmentType](https://learn.microsoft.com/windows/win32/api/directxcollision/ne-directxcollision-containmenttype) value indicating whether the triangle is contained within the planes.

## Remarks

**Note** `TriangleTests`::`ContainedBy` is new for DirectXMath. This functionality is not available in XNAMath 2.x.
Similar functionality for XNAMath can be found in the DirectX SDK Collision sample.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Triangle Test Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-triangletests)