# XPS_LINE_JOIN enumeration

## Description

Describes the joint made by two intersecting line segments.

## Constants

### `XPS_LINE_JOIN_MITER:1`

Produces a sharp or clipped corner, depending on whether the length of the miter exceeds the miter limit.

### `XPS_LINE_JOIN_BEVEL`

Produces a diagonal corner.

### `XPS_LINE_JOIN_ROUND`

Produces a smooth, circular arc between the lines.

## Remarks

In the illustration that follows, the shaded area at the vertex of the line segments in each example shows how the joint fill is determined by the value of **XPS_LINE_JOIN**.

![A diagram that shows examples of the different XPS_LINE_JOIN values](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/XPS_LINE_JOIN.png)

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)