# Graphics::DrawCurve(IN const Pen,IN const PointF,IN INT,IN INT,IN INT,IN REAL)

## Description

The **Graphics::DrawCurve** method draws a cardinal spline.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the cardinal spline.

### `points` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of
[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the coordinates that the cardinal spline passes through.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

### `offset` [in]

Type: **INT**

Integer that specifies the element in the
*points* array that specifies the point at which the cardinal spline begins.

### `numberOfSegments` [in]

Type: **INT**

Integer that specifies the number of segments in the cardinal spline.

### `tension` [in]

Type: **REAL**

Real number that specifies how tightly the curve bends through the coordinates of the cardinal spline.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline. The ending point of each segment is the starting point for the next. The
*numberOfSegments* parameter must not be greater than the
*count* parameter minus the
*offset* parameter plus one.

#### Examples

The following example draws a cardinal spline.

```cpp
VOID Example_DrawCurve5(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of PointF objects.
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

   // Specify offset, number of segments to draw, and tension.
   int offset = 1;
   int segments = 2;
   REAL tension = 1.0f;

   // Draw the curve.
   graphics.DrawCurve(&greenPen, curvePoints, 4, offset, segments, tension);

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

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)