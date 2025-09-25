# Polygon function

## Description

The **Polygon** function draws a polygon consisting of two or more vertices connected by straight lines. The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.

## Parameters

### `hdc` [in]

A handle to the device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that specify the vertices of the polygon, in logical coordinates.

### `cpt` [in]

The number of vertices in the array. This value must be greater than or equal to 2.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The polygon is closed automatically by drawing a line from the last vertex to the first.

The current position is neither used nor updated by the **Polygon** function.

Any extra points are ignored. To draw a line with more points, divide your data into groups, each of which have less than the maximum number of points, and call the function for each group of points. Remember to connect the line segments.

## See also

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[GetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpolyfillmode)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyPolygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolygon)

[Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)