# CloseFigure function

## Description

The **CloseFigure** function closes an open figure in a path.

## Parameters

### `hdc` [in]

Handle to the device context in which the figure will be closed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **CloseFigure** function closes the figure by drawing a line from the current position to the first point of the figure (usually, the point specified by the most recent call to the [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex) function) and then connects the lines by using the line join style. If a figure is closed by using the [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto) function instead of **CloseFigure**, end caps are used to create the corner instead of a join.

The **CloseFigure** function should only be called if there is an open path bracket in the specified device context.

A figure in a path is open unless it is explicitly closed by using this function. (A figure can be open even if the current point and the starting point of the figure are the same.)

After a call to **CloseFigure**, adding a line or curve to the path starts a new figure.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)