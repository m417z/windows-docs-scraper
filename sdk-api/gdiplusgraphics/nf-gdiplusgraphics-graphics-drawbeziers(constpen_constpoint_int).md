# Graphics::DrawBeziers(IN const Pen,IN const Point,IN INT)

## Description

The **Graphics::DrawBeziers** method draws a sequence of connected Bézier splines.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the Bézier splines.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the starting, ending, and control points of the Bézier splines. The ending coordinate of one Bézier spline is the starting coordinate of the next Bézier spline.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A Bézier spline does not pass through its control points. The control points act as magnets, pulling the curve in certain directions to influence the way the Bézier splines bend.

#### Examples

The following example draws a pair of Bézier curves.

```cpp

VOID Example_DrawBeziers(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of Point objects.
   Pen greenPen(Color(255, 0, 255, 0), 3);

   Point startPoint(100, 100);
   Point ctrlPoint1(200, 50);
   Point ctrlPoint2(400, 10);
   Point endPoint1(500, 100);
   Point ctrlPoint3(600, 200);
   Point ctrlPoint4(700, 400);
   Point endPoint2(500, 500);

   Point curvePoints[7] = {
      startPoint,
      ctrlPoint1,
      ctrlPoint2,
      endPoint1,
      ctrlPoint3,
      ctrlPoint4,
      endPoint2};

   // Draw the Bezier curves.
   graphics.DrawBeziers(&greenPen, curvePoints, 7);

   // Draw the control and end points.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   graphics.FillEllipse(&redBrush, Rect(100 - 5, 100 - 5, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(500 - 5, 100 - 5, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(500 - 5, 500 - 5, 10, 10));
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   graphics.FillEllipse(&blueBrush, Rect(200 - 5, 50 - 5, 10, 10));
   graphics.FillEllipse(&blueBrush, Rect(400 - 5, 10 - 5, 10, 10));
   graphics.FillEllipse(&blueBrush, Rect(600 - 5, 200 - 5, 10, 10));
   graphics.FillEllipse(&blueBrush, Rect(700 - 5, 400 - 5, 10, 10));
}
```

## See also

[Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-bezier-splines-about)

[DrawBezier Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbezier(inconstpen_inconstpointf__inconstpointf__inconstpointf__inconstpointf_))

[DrawBeziers](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbeziers(inconstpen_inconstpoint_inint))

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)