# FillPath function

## Description

The **FillPath** function closes any open figures in the current path and fills the path's interior by using the current brush and polygon-filling mode.

## Parameters

### `hdc` [in]

A handle to a device context that contains a valid path.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

After its interior is filled, the path is discarded from the DC identified by the *hdc* parameter.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)

[StrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokeandfillpath)

[StrokePath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokepath)