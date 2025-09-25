# GraphicsPath::AddCurve

## Description

The **GraphicsPath::AddCurve** method adds a cardinal spline to the current figure of this path.

## Parameters

### `points`

Pointer to an array of points that define the cardinal spline.
The cardinal spline is a curve that passes through each point in the array.

### `count`

Integer that specifies the number of elements in the points array.

## Return value

**Type:** [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You should keep a copy of the points array if those points will be needed later.
The **GraphicsPath** object does not store the points passed to the **AddClosedCurve** method; instead, it converts the cardinal spline to a sequence of Bézier splines and stores the points that define those Bézier splines.
You cannot retrieve the original array of points from the GraphicsPath object.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object path, adds a cardinal spline to path, and then draws path.

```cpp
VOID AddCurveExample(HDC hdc)
{
   Graphics graphics(hdc);
   PointF pts[] = {PointF(50.0f, 50.0f),
                   PointF(60.0f, 20.0f),
                   PointF(70.0f, 100.0f),
                   PointF(80.0f, 50.0f)};
   GraphicsPath path;
   path.AddCurve(pts, 4);
   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

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

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)