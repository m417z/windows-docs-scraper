# XPS_SEGMENT_TYPE enumeration

## Description

Describes a line segment.

## Constants

### `XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE:1`

The line segment is an arc that covers more than 180 degrees and is drawn in a clockwise direction from the start point to the end point.

### `XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE`

The line segment is an arc that covers more than 180 degrees and is drawn in a counterclockwise direction from the start point to the end point.

### `XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE`

The line segment is an arc that covers at most 180 degrees and is drawn in a clockwise direction from the start point to the end point.

### `XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE`

The line segment is an arc that covers at most 180 degrees and is drawn in a counterclockwise direction from the start point to the end point.

### `XPS_SEGMENT_TYPE_BEZIER`

The line segment is a cubic Bezier curve that is drawn between two points.

### `XPS_SEGMENT_TYPE_LINE`

The line segment is a straight line that is drawn between two points.

### `XPS_SEGMENT_TYPE_QUADRATIC_BEZIER`

The line segment is a quadratic Bezier curve that is drawn between two points.

## Remarks

A geometry segment is described by the start point, the segment type, and additional parameters whose values are determined by the segment type. The coordinates for the start point of the first segment are a property of the geometry figure. The start point of each subsequent segment is the end point of the preceding segment.

The table that follows shows an example of each segment type.

| Examples | |
| --- | --- |
| XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE ![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lc.png) | XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE ![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lcc.png) |
| XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_sc.png) | XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE ![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_scc.png) |
| XPS_SEGMENT_TYPE_BEZIER ![A diagram that shows an example of an XPS_SEGMENT_TYPE_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_bezier.png) | XPS_SEGMENT_TYPE_LINE ![A diagram that shows an example of an XPS_SEGMENT_TYPE_LINE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_line.png) |
| XPS_SEGMENT_TYPE_QUADRATIC_BEZIER ![A diagram that shows an example of an XPS_SEGMENT_TYPE_QUADRATIC_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_quad_bezier.png) |  |

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)