# Intersects(XMVECTOR, XMVECTOR, XMVECTOR, XMVECTOR, XMVECTOR, XMVECTOR) method

## Description

Test whether two triangles intersect.

## Parameters

### `A0`

A vector defining triangle A.

### `A1`

A vector defining triangle A.

### `A2`

A vector defining triangle A.

### `B0`

A vector defining triangle B.

### `B1`

A vector defining triangle B.

### `B2`

A vector defining triangle B.

## Return value

A boolean value indicating whether the triangles intersect.

## Remarks

Typically the six planes passed to this function represent a frustum.

**Note** `TriangleTests::Intersects` is new for DirectXMath. This functionality is not available in XNAMath 2.x.
Similar functionality for XNAMath can be found in the DirectX SDK Collision sample.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8.
Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Triangle Test Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-triangletests)