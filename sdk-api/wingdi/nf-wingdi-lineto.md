# LineTo function

## Description

The **LineTo** function draws a line from the current position up to, but not including, the specified point.

## Parameters

### `hdc` [in]

Handle to a device context.

### `x` [in]

Specifies the x-coordinate, in logical units, of the line's ending point.

### `y` [in]

Specifies the y-coordinate, in logical units, of the line's ending point.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The line is drawn by using the current pen and, if the pen is a geometric pen, the current brush.

If **LineTo** succeeds, the current position is set to the specified ending point.

#### Examples

For an example, see [Drawing Markers](https://learn.microsoft.com/windows/desktop/gdi/drawing-markers).

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)