# Arc function

## Description

The **Arc** function draws an elliptical arc.

## Parameters

### `hdc` [in]

A handle to the device context where drawing takes place.

### `x1` [in]

The x-coordinate, in logical units, of the upper-left corner of the bounding rectangle.

### `y1` [in]

The y-coordinate, in logical units, of the upper-left corner of the bounding rectangle.

### `x2` [in]

The x-coordinate, in logical units, of the lower-right corner of the bounding rectangle.

### `y2` [in]

The y-coordinate, in logical units, of the lower-right corner of the bounding rectangle.

### `x3` [in]

The x-coordinate, in logical units, of the ending point of the radial line defining the starting point of the arc.

### `y3` [in]

The y-coordinate, in logical units, of the ending point of the radial line defining the starting point of the arc.

### `x4` [in]

The x-coordinate, in logical units, of the ending point of the radial line defining the ending point of the arc.

### `y4` [in]

The y-coordinate, in logical units, of the ending point of the radial line defining the ending point of the arc.

## Return value

If the arc is drawn, the return value is nonzero.

If the arc is not drawn, the return value is zero.

## Remarks

The points (*nLeftRect*, *nTopRect*) and (*nRightRect*, *nBottomRect*) specify the bounding rectangle. An ellipse formed by the specified bounding rectangle defines the curve of the arc. The arc extends in the current drawing direction from the point where it intersects the radial from the center of the bounding rectangle to the (*nXStartArc*, *nYStartArc*) point. The arc ends where it intersects the radial from the center of the bounding rectangle to the (*nXEndArc*, *nYEndArc*) point. If the starting point and ending point are the same, a complete ellipse is drawn.

The arc is drawn using the current pen; it is not filled.

The current position is neither used nor updated by **Arc**.

Use the [GetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getarcdirection) and [SetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setarcdirection) functions to get and set the current drawing direction for a device context. The default drawing direction is counterclockwise.

## See also

[AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)

[ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)

[Chord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-chord)

[Ellipse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ellipse)

[GetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getarcdirection)

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[Pie](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pie)

[SetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setarcdirection)