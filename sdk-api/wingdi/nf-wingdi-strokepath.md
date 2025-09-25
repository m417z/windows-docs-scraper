# StrokePath function

## Description

The **StrokePath** function renders the specified path by using the current pen.

## Parameters

### `hdc` [in]

Handle to a device context that contains the completed path.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The path, if it is to be drawn by **StrokePath**, must have been completed through a call to [EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath). Calling this function on a path for which **EndPath** has not been called will cause this function to fail and return zero. Unlike other path drawing functions such as [StrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokeandfillpath), **StrokePath** will not attempt to close the path by drawing a straight line from the first point on the path to the last point on the path.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)