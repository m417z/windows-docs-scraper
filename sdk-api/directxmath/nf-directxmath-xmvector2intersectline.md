# XMVector2IntersectLine function

## Description

Finds the intersection of two lines.

## Parameters

### `Line1Point1` [in]

2D vector describing the first point on the first line.

### `Line1Point2` [in]

2D vector describing a second point on the first line.

### `Line2Point1` [in]

2D vector describing the first point on the second line.

### `Line2Point2` [in]

2D vector describing a second point on the second line.

## Return value

Returns the intersection point. If the lines are parallel, the returned vector will be a NaN. If the two lines are coincident, the returned vector will be positive infinity.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 2D Vector Geometric Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector2-geometric)