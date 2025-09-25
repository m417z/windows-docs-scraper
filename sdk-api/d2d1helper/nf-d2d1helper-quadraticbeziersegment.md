# QuadraticBezierSegment function

## Description

Creates a [D2D1_QUADRATIC_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_quadratic_bezier_segment) structure.

## Parameters

### `point1` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The control point of the quadratic Bezier segment.

### `point2` [in, ref]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The end point of the quadratic Bezier segment.

## Return value

Type: **[D2D1_QUADRATIC_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_quadratic_bezier_segment)**

The new quadratic Bezier curve segment.