# GraphicsPath::AddBeziers(IN const Point,IN INT)

## Description

The **GraphicsPath::AddBeziers** method adds a sequence of connected Bézier splines to the current figure of this path.

## Parameters

### `points` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of starting points, ending points, and control points for the connected splines. The first spline is constructed from the first point through the fourth point in the array and uses the second and third points as control points. Each subsequent spline in the sequence needs exactly three more points: the ending point of the previous spline is used as the starting point, the next two points in the sequence are control points, and the third point is the ending point.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[AddBezier Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbezier(inconstpoint__inconstpoint__inconstpoint__inconstpoint_))

[AddBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbeziers(inconstpoint_inint))

[AddCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addcurve(inconstpointf_inint_inint_inint_inreal))

[Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-bezier-splines-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)