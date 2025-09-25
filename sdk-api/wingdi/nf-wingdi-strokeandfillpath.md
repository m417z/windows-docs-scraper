# StrokeAndFillPath function

## Description

The **StrokeAndFillPath** function closes any open figures in a path, strokes the outline of the path by using the current pen, and fills its interior by using the current brush.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The device context identified by the *hdc* parameter must contain a closed path.

The **StrokeAndFillPath** function has the same effect as closing all the open figures in the path, and stroking and filling the path separately, except that the filled region will not overlap the stroked region even if the pen is wide.

#### Examples

For an example, see [Drawing a Pie Chart](https://learn.microsoft.com/windows/desktop/gdi/drawing-a-pie-chart).

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[FillPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillpath)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)

[StrokePath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokepath)