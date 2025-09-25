# DrawBeziers(Pen*,PointF*,INT)

## Description

The **Graphics::DrawBeziers** method draws a sequence of connected Bézier splines.

## Parameters

### `pen`

Pointer to a pen that is used to draw the Bézier splines.

### `points`

Pointer to an array of [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the starting, ending, and control points of the Bézier splines.

### `count`

Integer that specifies the number of elements in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

A Bézier spline does not pass through its control points.
The control points act as magnets, pulling the curve in certain directions to influence the way a Bézier spline bends.
Each Bézier spline requires a starting point and an ending point.
Each ending point is the starting point for the next Bézier spline.

#### Examples

The following example draws a pair of Bézier curves.

```cpp
VOID Example_DrawBeziers2(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of PointF objects.
   Pen greenPen(Color(255, 0, 255, 0), 3);

   PointF startPoint(100.0f, 100.0f);
   PointF ctrlPoint1(200.0f, 50.0f);
   PointF ctrlPoint2(400.0f, 10.0f);
   PointF endPoint1(500.0f, 100.0f);
   PointF ctrlPoint3(600.0f, 200.0f);
   PointF ctrlPoint4(700.0f, 400.0f);
   PointF endPoint2(500.0f, 500.0f);

   PointF curvePoints[7] = {
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

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[DrawBeziers](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawbeziers(inconstpen_inconstpoint_inint))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)