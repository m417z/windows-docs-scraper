# GraphicsPath::AddCurve(IN const Point,IN INT,IN INT,IN INT,IN REAL)

## Description

The **GraphicsPath::AddCurve** method adds a cardinal spline to the current figure of this path.

## Parameters

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of points that define the cardinal spline. The cardinal spline is a curve that passes through a subset (specified by the *offset* and *numberOfSegments* parameters) of the points in the array.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array.

### `offset` [in]

Type: **INT**

Integer that specifies the index of the array element that is used as the first point of the cardinal spline.

### `numberOfSegments` [in]

Type: **INT**

Integer that specifies the number of segments in the cardinal spline. Segments are the curves that connect consecutive points in the array.

### `tension` [in]

Type: **REAL**

Nonnegative real number that controls the length of the curve and how the curve bends. A value of 0 specifies that the spline is a sequence of straight line segments. As the value increases, the curve becomes fuller.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You should keep a copy of the *points* array if those points will be needed later. The [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object does not store the points passed to the **AddClosedCurve** method; instead, it converts the cardinal spline to a sequence of Bézier splines and stores the points that define those Bézier splines. You cannot retrieve the original array of points from the
**GraphicsPath** object.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds a cardinal spline to *path*, and then draws *path*. The spline is built from the points indexed 2 through 6 in an array of eight points.

```cpp
VOID AddCurveExample2(HDC hdc)
{
   GraphicsPath   path;
   Graphics graphics(hdc);

   Point pts[] = {Point(50, 50),
                  Point(70, 80),
                  Point(100, 100),
                  Point(130, 40),
                  Point(150, 90),
                  Point(180, 30),
                  Point(210, 120),
                  Point(240, 80)};
   path.AddCurve(
      pts,
      8,     // There are eight points in the array.
      2,     // Start at the point with index 2.
      4,     // Four segments. End at the point with index 6.
      1.0f);
   Pen pen(Color(255, 0, 0, 255));
   graphics.DrawPath(&pen, &path);
   // Draw all eight points in the array.
   SolidBrush brush(Color(255, 255, 0, 0));
   for(INT j = 0; j <= 7; ++j)
      graphics.FillEllipse(&brush, pts[j].X - 3, pts[j].Y - 3, 6, 6);
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