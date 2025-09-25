# Graphics::DrawBezier(IN const Pen,IN const Point &,IN const Point &,IN const Point &,IN const Point &)

## Description

The **Graphics::DrawBezier** method draws a Bézier spline.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the Bézier spline.

### `pt1` [in, ref]

Type: **const POINT**

Reference to the starting point of the Bézier spline.

### `pt2` [in, ref]

Type: **const POINT**

Reference to the first control point of the Bézier spline.

### `pt3` [in, ref]

Type: **const POINT**

Reference to the second control point of the Bézier spline.

### `pt4` [in, ref]

Type: **const POINT**

Reference to the ending point of the Bézier spline.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A Bézier spline does not pass through its control points. The control points act as magnets, pulling the curve in certain directions to influence the way the Bézier spline bends.

#### Examples

The following example draws a Bézier curve.

```cpp

VOID Example_DrawBezier(HDC hdc)
{
   Graphics graphics(hdc);

   // Set up the pen and curve points.
   Pen greenPen(Color(255, 0, 255, 0));
   Point startPoint(100, 100);
   Point controlPoint1(200, 10);
   Point controlPoint2(350, 50);
   Point endPoint(500, 100);

   //Draw the curve.
   graphics.DrawBezier(&greenPen, startPoint, controlPoint1, controlPoint2, endPoint);

   //Draw the end points and control points.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   graphics.FillEllipse(&redBrush, 100 - 5, 100 - 5, 10, 10);
   graphics.FillEllipse(&redBrush, 500 - 5, 100 - 5, 10, 10);
   graphics.FillEllipse(&blueBrush, 200 - 5, 10 - 5, 10, 10);
   graphics.FillEllipse(&blueBrush, 350 - 5, 50 - 5, 10, 10);
}
```

## See also

[Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-bezier-splines-about)

[DrawBezier](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbezier(inconstpen_inconstpointf__inconstpointf__inconstpointf__inconstpointf_))

[DrawBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbeziers(inconstpen_inconstpoint_inint))

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)