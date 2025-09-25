# D2D1_BEZIER_SEGMENT structure

## Description

Represents a cubic bezier segment drawn between two points.

## Members

### `point1`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The first control point for the Bezier segment.

### `point2`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The second control point for the Bezier segment.

### `point3`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The end point for the Bezier segment.

## Remarks

A cubic Bezier curve is defined by four points: a start point, an end point (*point3*), and two control points (*point1* and *point2*). A Bezier segment does not contain a property for the starting point of the curve; it defines only the end point. The beginning point of the curve is the current point of the path to which the Bezier curve is added.

The two control points of a cubic Bezier curve behave like magnets, attracting portions of what would otherwise be a straight line toward themselves and producing a curve. The first control point, *point1*, affects the beginning portion of the curve; the second control point, *point2*, affects the ending portion of the curve.

**Note** The curve doesn't necessarily pass through either of the control points; each control point moves its portion of the line toward itself, but not through itself.