# Chord function

## Description

The **Chord** function draws a chord (a region bounded by the intersection of an ellipse and a line segment, called a secant). The chord is outlined by using the current pen and filled by using the current brush.

## Parameters

### `hdc` [in]

A handle to the device context in which the chord appears.

### `x1` [in]

The x-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.

### `y1` [in]

The y-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.

### `x2` [in]

The x-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.

### `y2` [in]

The y-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.

### `x3` [in]

The x-coordinate, in logical coordinates, of the endpoint of the radial defining the beginning of the chord.

### `y3` [in]

The y-coordinate, in logical coordinates, of the endpoint of the radial defining the beginning of the chord.

### `x4` [in]

The x-coordinate, in logical coordinates, of the endpoint of the radial defining the end of the chord.

### `y4` [in]

The y-coordinate, in logical coordinates, of the endpoint of the radial defining the end of the chord.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The curve of the chord is defined by an ellipse that fits the specified bounding rectangle. The curve begins at the point where the ellipse intersects the first radial and extends counterclockwise to the point where the ellipse intersects the second radial. The chord is closed by drawing a line from the intersection of the first radial and the curve to the intersection of the second radial and the curve.

If the starting point and ending point of the curve are the same, a complete ellipse is drawn.

The current position is neither used nor updated by **Chord**.

## See also

[AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)

[Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)

[ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[Pie](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pie)