# Pie function

## Description

The **Pie** function draws a pie-shaped wedge bounded by the intersection of an ellipse and two radials. The pie is outlined by using the current pen and filled by using the current brush.

## Parameters

### `hdc` [in]

A handle to the device context.

### `left` [in]

The x-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.

### `top` [in]

The y-coordinate, in logical coordinates, of the upper-left corner of the bounding rectangle.

### `right` [in]

The x-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.

### `bottom` [in]

The y-coordinate, in logical coordinates, of the lower-right corner of the bounding rectangle.

### `xr1` [in]

The x-coordinate, in logical coordinates, of the endpoint of the first radial.

### `yr1` [in]

The y-coordinate, in logical coordinates, of the endpoint of the first radial.

### `xr2` [in]

The x-coordinate, in logical coordinates, of the endpoint of the second radial.

### `yr2` [in]

The y-coordinate, in logical coordinates, of the endpoint of the second radial.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The curve of the pie is defined by an ellipse that fits the specified bounding rectangle. The curve begins at the point where the ellipse intersects the first radial and extends counterclockwise to the point where the ellipse intersects the second radial.

The current position is neither used nor updated by the **Pie** function.

## See also

[AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)

[Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)

[ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)

[Chord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-chord)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)