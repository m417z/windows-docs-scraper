# GraphicsPathIterator::NextPathType

## Description

The **GraphicsPathIterator::NextPathType** method gets the starting index and the ending index of the next group of data points that all have the same type.

## Parameters

### `pathType` [out]

Type: **BYTE***

Pointer to a **BYTE** that receives the point type shared by all points in the group. Possible values are PathPointTypeLine and PathPointTypeBezier, which are elements of the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

### `startIndex` [out]

Type: **INT***

Pointer to an **INT** that receives the starting index of the group of points.

### `endIndex` [out]

Type: **INT***

Pointer to an **INT** that receives the ending index of the group of points.

## Return value

Type: **INT**

This method returns the number of data points in the group. If there are no more groups in the path, this method returns 0.

## Remarks

A path has an array of data points that define its lines and curves. All curves in the path are represented as Bézier splines, so a given point in the array has one of two types: PathPointTypeLine or PathPointTypeBezier.

The first time you call the [GraphicsPathIterator::NextSubpath](https://learn.microsoft.com/previous-versions/ms535462(v=vs.85)) method of an iterator, it gets the starting and ending indices of the first group of points that all have the same type. The second time, it gets the second group, and so on. Each time you call **GraphicsPathIterator::NextSubpath**, it returns the number of data points in the obtained group. When there are no groups remaining, it returns 0.

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::CopyData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-copydata)

[GraphicsPathIterator::NextMarker Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[GraphicsPathIterator::NextSubpath Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)