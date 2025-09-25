# Ellipse function

## Description

The **Ellipse** function draws an ellipse. The center of the ellipse is the center of the specified bounding rectangle. The ellipse is outlined by using the current pen and is filled by using the current brush.

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

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The current position is neither used nor updated by **Ellipse**.

#### Examples

For an example, see [Using Filled Shapes](https://learn.microsoft.com/windows/desktop/gdi/using-filled-shapes).

## See also

[Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)

[ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)