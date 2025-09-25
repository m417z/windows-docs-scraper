# Graphics::DrawClosedCurve(IN const Pen,IN const Point,IN INT,IN REAL)

## Description

The **Graphics::DrawClosedCurve** method draws a closed cardinal spline.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the closed cardinal spline.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the coordinates of the closed cardinal spline. The array of **Point** objects must contain a minimum of three elements.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

### `tension` [in]

Type: **REAL**

Real number that specifies how tightly the curve bends through the coordinates of the closed cardinal spline.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Each ending point is the starting point for the next cardinal spline. In a closed cardinal spline, the curve continues through the last point in the
*points* array and connects with the first point in the array.

#### Examples

The following example draws a closed cardinal spline.

```cpp

VOID Example_DrawClosedCurve2(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a Pen object and an array of Point objects.
   Pen greenPen(Color(255, 0, 0, 255), 3);
   Point point1(100, 100);
   Point point2(200, 50);
   Point point3(400, 10);
   Point point4(500, 100);
   Point point5(600, 200);
   Point point6(700, 400);
   Point point7(500, 500);

   Point curvePoints[7] = {
      point1,
      point2,
      point3,
      point4,
      point5,
      point6,
      point7};

   // Draw the closed curve.
   graphics.DrawClosedCurve(&greenPen, curvePoints, 7, 1.0);

   // Draw the points in the curve.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   graphics.FillEllipse(&redBrush, Rect(95, 95, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(495, 95, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(495, 495, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(195, 45, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(395, 5, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(595, 195, 10, 10));
   graphics.FillEllipse(&redBrush, Rect(695, 395, 10, 10));
}
```

## See also

[Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cardinal-splines-about)

[DrawCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawcurve(inconstpen_inconstpointf_inint_inint_inint_inreal))

[Drawing Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-cardinal-splines-use)

[FillClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillclosedcurve(inconstbrush_inconstpointf_inint_infillmode_inreal))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)