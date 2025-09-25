# DrawCurve(Pen*,PointF*,INT)

## Description

The **Graphics::DrawCurve** method draws a cardinal spline.

## Parameters

### `pen`

Pointer to a pen used to draw the cardinal spline.

### `points`

Pointer to an array of [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the coordinates that the cardinal spline passes through.

### `count`

Integer that specifies the number of elements in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline.
The ending point of each segment is the starting point for the next.

#### Examples

The following example draws a cardinal spline.

```cpp
VOID Example_DrawCurve4(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of Point objects.
   Pen greenPen(Color::Green, 3);
   PointF point1(100.0f, 100.0f);
   PointF point2(200.0f, 50.0f);
   PointF point3(400.0f, 10.0f);
   PointF point4(500.0f, 100.0f);

   PointF curvePoints[4] = {
   point1,
   point2,
   point3,
   point4};

   PointF* pcurvePoints = curvePoints;

   // Draw the curve.
   graphics.DrawCurve(&greenPen, curvePoints, 4);

   //Draw the points in the curve.
   SolidBrush redBrush(Color::Red);
   graphics.FillEllipse(&redBrush, Rect(95, 95, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(195, 45, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(395, 5, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(495, 95, 10, 10));
}
```

## See also

[Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cardinal-splines-about)

[DrawClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawclosedcurve(inconstpen_inconstpointf_inint_inreal))

[Drawing Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-cardinal-splines-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)