# RoundRect function

## Description

The **RoundRect** function draws a rectangle with rounded corners. The rectangle is outlined by using the current pen and filled by using the current brush.

## Parameters

### `hdc` [in]

A handle to the device context.

### `left` [in]

The x-coordinate, in logical coordinates, of the upper-left corner of the rectangle.

### `top` [in]

The y-coordinate, in logical coordinates, of the upper-left corner of the rectangle.

### `right` [in]

The x-coordinate, in logical coordinates, of the lower-right corner of the rectangle.

### `bottom` [in]

The y-coordinate, in logical coordinates, of the lower-right corner of the rectangle.

### `width` [in]

The width, in logical coordinates, of the ellipse used to draw the rounded corners.

### `height` [in]

The height, in logical coordinates, of the ellipse used to draw the rounded corners.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The current position is neither used nor updated by this function.

#### Examples

For an example, see [Using Filled Shapes](https://learn.microsoft.com/windows/desktop/gdi/using-filled-shapes).

## See also

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[Rectangle](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectangle)