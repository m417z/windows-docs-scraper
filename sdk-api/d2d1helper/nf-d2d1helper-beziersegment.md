# BezierSegment function

## Description

Creates a [D2D1_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_bezier_segment) structure.

## Parameters

### `point1` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The first control point for the Bezier segment.

### `point2` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The second control point for the Bezier segment.

### `point3` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The end point for the Bezier segment.

## Return value

Type: **[D2D1_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_bezier_segment)**

The new Bezier segment.

## See also

[ID2D1GeometrySink](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometrysink)