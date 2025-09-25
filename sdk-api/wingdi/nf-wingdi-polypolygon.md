# PolyPolygon function

## Description

The **PolyPolygon** function draws a series of closed polygons. Each polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode. The polygons drawn by this function can overlap.

## Parameters

### `hdc` [in]

A handle to the device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that define the vertices of the polygons, in logical coordinates. The polygons are specified consecutively. Each polygon is closed automatically by drawing a line from the last vertex to the first. Each vertex should be specified once.

### `asz` [in]

A pointer to an array of integers, each of which specifies the number of points in the corresponding polygon. Each integer must be greater than or equal to 2.

### `csz` [in]

The total number of polygons.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The current position is neither used nor updated by this function.

Any extra points are ignored. To draw the polygons with more points, divide your data into groups, each of which have less than the maximum number of points, and call the function for each group of points. Note, it is best to have a polygon in only one of the groups.

## See also

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[GetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpolyfillmode)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Polygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polygon)

[Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)