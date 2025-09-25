# BeginPath function

## Description

The **BeginPath** function opens a path bracket in the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

After a path bracket is open, an application can begin calling GDI drawing functions to define the points that lie in the path. An application can close an open path bracket by calling the [EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath) function.

When an application calls **BeginPath** for a device context, any previous paths are discarded from that device context. The following list shows which drawing functions can be used.

* [AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)
* [Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc)
* [ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto)
* [Chord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-chord)
* [CloseFigure](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-closefigure)
* [Ellipse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ellipse)
* [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)
* [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)
* [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)
* [Pie](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pie)
* [PolyBezier](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezier)
* [PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto)
* [PolyDraw](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polydraw)
* [Polygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polygon)
* [Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)
* [PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)
* [PolyPolygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolygon)
* [PolyPolyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolyline)
* [Rectangle](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectangle)
* [RoundRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-roundrect)
* [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)

#### Examples

For an example, see [Using Paths](https://learn.microsoft.com/windows/desktop/gdi/using-paths).

## See also

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[FillPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillpath)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[PathToRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pathtoregion)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[SelectClipPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectclippath)

[StrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokeandfillpath)

[StrokePath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-strokepath)

[WidenPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-widenpath)