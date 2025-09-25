# FillClosedCurve(Brush*,PointF*,INT)

## Description

The **Graphics::FillClosedCurve** method creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the spline.

### `points`

Pointer to an array of points that this method uses to create a closed cardinal spline. Each point in the array is a point on the spline.

### `count`

Integer that specifies the number of points in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example fills a closed cardinal spline.

```cpp
VOID Example_FillClosedCurve3(HDC hdc)
{
   Graphics graphics(hdc);

   //Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   //Create an array of PointF objects.
   PointF point1(100.0f, 100.0f);
   PointF point2(200.0f, 50.0f);
   PointF point3(250.0f, 200.0f);
   PointF point4(50.0f, 150.0f);
   PointF points[4] = {point1, point2, point3, point4};

   //Fill the curve.
   graphics.FillClosedCurve(&blackBrush, points, 4);
}
```

## See also

[Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-cardinal-splines-about)

[Drawing Cardinal Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-cardinal-splines-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)