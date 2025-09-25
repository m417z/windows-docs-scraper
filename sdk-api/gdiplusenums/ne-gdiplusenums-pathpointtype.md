## Description

The **PathPointType** enumeration indicates point types and flags for the data points in a path. Bits 0 through 2 indicate the type of a point, and bits 3 through 7 hold a set of flags that specify attributes of a point. This enumeration is used by the [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath), [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator), and [PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata) classes.

## Constants

### `PathPointTypeStart:0`

Indicates that the point is the start of a figure.

### `PathPointTypeLine:1`

Indicates that the point is one of the two endpoints of a line.

### `PathPointTypeBezier:3`

Indicates that the point is an endpoint or control point of a cubic Bézier spline.

### `PathPointTypePathTypeMask:0x07`

Masks all bits except for the three low-order bits, which indicate the point type.

### `PathPointTypeDashMode:0x10`

Not used.

### `PathPointTypePathMarker:0x20`

Specifies that the point is a marker.

### `PathPointTypeCloseSubpath:0x80`

Specifies that the point is the last point in a closed subpath (figure).

### `PathPointTypeBezier3:3`

Indicates that the point is an endpoint or control point of a cubic Bézier spline.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points.

## See also

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)