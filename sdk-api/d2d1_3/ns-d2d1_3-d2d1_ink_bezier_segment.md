# D2D1_INK_BEZIER_SEGMENT structure

## Description

Represents a Bezier segment to be used in the creation of an [ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink) object.
This structure differs from [D2D1_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1/ns-d2d1-d2d1_bezier_segment) in that it is composed
of [D2D1_INK_POINT](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_point)s, which contain a radius in addition to x- and y-coordinates.

## Members

### `point1`

The first control point for the Bezier segment.

### `point2`

The second control point for the Bezier segment.

### `point3`

The end point for the Bezier segment.