# GraphicsPath::AddClosedCurve(IN const Point,IN INT,IN REAL)

## Description

The **GraphicsPath::AddClosedCurve** method adds a closed cardinal spline to this path.

## Parameters

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of points that define the cardinal spline. The cardinal spline is a curve that passes through each point in the array.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

### `tension` [in]

Type: **REAL**

Nonnegative real number that controls the length of the curve and how the curve bends. A value of 0 specifies that the spline is a sequence of straight lines. As the value increases, the curve becomes fuller.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You should keep a copy of the *points* array if those points will be needed later. The [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object does not store the points passed to the **GraphicsPath::AddClosedCurve** method; instead, it converts the cardinal spline to a sequence of Bézier splines and stores the points that define those Bézier splines. You cannot retrieve the original array of points from the **GraphicsPath** object.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds a closed cardinal spline to *path*, and then draws *path*. The tension is set to 1.0.

```cpp
VOID Example_AddClosedCurve(HDC hdc)
{
   Graphics graphics(hdc);

   Point pts[] = {Point(50,50),
                  Point(60,20),
                  Point(70,100),
                  Point(80,50)};

   GraphicsPath path;
   path.AddClosedCurve(pts, 4, 1.0f);

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddBezier Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbezier(inconstpoint__inconstpoint__inconstpoint__inconstpoint_))

[AddBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbeziers(inconstpoint_inint))

[AddClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addclosedcurve(inconstpointf_inint_inreal))

[AddCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addcurve(inconstpointf_inint_inint_inint_inreal))

[Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cardinal-splines-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Drawing Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-cardinal-splines-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)