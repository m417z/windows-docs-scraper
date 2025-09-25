# GraphicsPath::SetMarker

## Description

The **GraphicsPath::SetMarker** method designates the last point in this path as a marker point.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

Each time you add a line, curve, or shape to a path, the point array and the type array are expanded. When you call **GraphicsPath::SetMarker**, a marker flag is placed in the last byte of the type array. That flag designates the last point of the point array as a marker point.

Markers divide a path into sections. You can use a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object to draw selected sections of a path.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::CloseFigure](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-closefigure)

[GraphicsPath::GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[GraphicsPath::StartFigure](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-startfigure)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::NextMarker Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[GraphicsPathIterator::NextSubpath Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)