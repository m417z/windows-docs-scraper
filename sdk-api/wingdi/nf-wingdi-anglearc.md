# AngleArc function

## Description

The **AngleArc** function draws a line segment and an arc. The line segment is drawn from the current position to the beginning of the arc. The arc is drawn along the perimeter of a circle with the given radius and center. The length of the arc is defined by the given start and sweep angles.

## Parameters

### `hdc` [in]

Handle to a device context.

### `x` [in]

Specifies the x-coordinate, in logical units, of the center of the circle.

### `y` [in]

Specifies the y-coordinate, in logical units, of the center of the circle.

### `r` [in]

Specifies the radius, in logical units, of the circle. This value must be positive.

### `StartAngle` [in]

Specifies the start angle, in degrees, relative to the x-axis.

### `SweepAngle` [in]

Specifies the sweep angle, in degrees, relative to the starting angle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **AngleArc** function moves the current position to the ending point of the arc.

The arc drawn by this function may appear to be elliptical, depending on the current transformation and mapping mode. Before drawing the arc, **AngleArc** draws the line segment from the current position to the beginning of the arc.

The arc is drawn by constructing an imaginary circle around the specified center point with the specified radius. The starting point of the arc is determined by measuring counterclockwise from the x-axis of the circle by the number of degrees in the start angle. The ending point is similarly located by measuring counterclockwise from the starting point by the number of degrees in the sweep angle.

If the sweep angle is greater than 360 degrees, the arc is swept multiple times.

This function draws lines by using the current pen. The figure is not filled.

#### Examples

For an example, see [Drawing a Pie Chart](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-pie-chart).

## See also

[Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)

[ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)