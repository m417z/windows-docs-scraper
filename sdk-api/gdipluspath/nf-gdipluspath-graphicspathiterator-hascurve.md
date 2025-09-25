# GraphicsPathIterator::HasCurve

## Description

The **GraphicsPathIterator::HasCurve** method determines whether the path has any curves.

## Return value

Type: **BOOL**

If the path has at least one curve, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

All curves in a path are stored as sequences of Bézier splines. For example, when you add an ellipse to a path, you specify the upper-left corner, the width, and the height of the ellipse's bounding rectangle. Those numbers (upper-left corner, width, and height) are not stored in the path; instead; the ellipse is converted to a sequence of four Bézier splines. The path stores the endpoints and control points of those Bézier splines.

A path stores an array of data points, each of which belongs to a line or a Bézier spline. If some of the points in the array belong to Bézier splines, then **GraphicsPathIterator::HasCurve** returns **TRUE**. If all points in the array belong to lines, then **GraphicsPathIterator::HasCurve** returns **FALSE**.

Certain methods flatten a path, which means that all the curves in the path are converted to sequences of lines. After a path has been flattened, **GraphicsPathIterator::HasCurve** will always return **FALSE**. Flattening happens when you call the [Flatten](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-flatten), [Widen](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-widen), or [Warp](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-warp) method of the [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) class.

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Flatten](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-flatten)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::CopyData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-copydata)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Warp](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-warp)

[Widen](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-widen)