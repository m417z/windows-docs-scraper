# Graphics::DrawCurve(IN const Pen,IN const Point,IN INT,IN REAL)

## Description

The **Graphics::DrawCurve** method draws a cardinal spline.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the cardinal spline.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the coordinates that the cardinal spline passes through.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

### `tension` [in]

Type: **REAL**

Real number that specifies how tightly the curve bends through the coordinates of the cardinal spline.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
**Status** enumeration.

## Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline. The ending point of each segment is the starting point for the next.

#### Examples

The following example draws a cardinal spline.

```cpp
VOID Example_DrawCurve3(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of Point objects.
   Pen greenPen(Color::Green, 3);
   Point point1(100, 100);
   Point point2(200, 50);
   Point point3(400, 10);
   Point point4(500, 100);

   Point curvePoints[4] = {
   point1,
   point2,
   point3,
   point4};

   Point* pcurvePoints = curvePoints;

   // Draw the curve.
   graphics.DrawCurve(&greenPen, curvePoints, 4, 1.0);

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