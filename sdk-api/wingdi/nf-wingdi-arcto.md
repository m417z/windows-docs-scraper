# ArcTo function

## Description

The **ArcTo** function draws an elliptical arc.

## Parameters

### `hdc` [in]

A handle to the device context where drawing takes place.

### `left` [in]

The x-coordinate, in logical units, of the upper-left corner of the bounding rectangle.

### `top` [in]

The y-coordinate, in logical units, of the upper-left corner of the bounding rectangle.

### `right` [in]

The x-coordinate, in logical units, of the lower-right corner of the bounding rectangle.

### `bottom` [in]

The y-coordinate, in logical units, of the lower-right corner of the bounding rectangle.

### `xr1` [in]

The x-coordinate, in logical units, of the endpoint of the radial defining the starting point of the arc.

### `yr1` [in]

The y-coordinate, in logical units, of the endpoint of the radial defining the starting point of the arc.

### `xr2` [in]

The x-coordinate, in logical units, of the endpoint of the radial defining the ending point of the arc.

### `yr2` [in]

The y-coordinate, in logical units, of the endpoint of the radial defining the ending point of the arc.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

**ArcTo** is similar to the [Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc) function, except that the current position is updated.

The points (*nLeftRect*, *nTopRect*) and (*nRightRect*, *nBottomRect*) specify the bounding rectangle. An ellipse formed by the specified bounding rectangle defines the curve of the arc. The arc extends counterclockwise from the point where it intersects the radial line from the center of the bounding rectangle to the (*nXRadial1*, *nYRadial1*) point. The arc ends where it intersects the radial line from the center of the bounding rectangle to the (*nXRadial2*, *nYRadial2*) point. If the starting point and ending point are the same, a complete ellipse is drawn.

A line is drawn from the current position to the starting point of the arc. If no error occurs, the current position is set to the ending point of the arc.

The arc is drawn using the current pen; it is not filled.

## See also

[AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)

[Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[SetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setarcdirection)