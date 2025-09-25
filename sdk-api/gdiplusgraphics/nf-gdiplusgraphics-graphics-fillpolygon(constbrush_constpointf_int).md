# FillPolygon(Brush*,PointF*,INT)

## Description

The **Graphics::FillPolygon** method uses a brush to fill the interior of a polygon.

## Parameters

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to paint the interior of the polygon.

### `points`

Pointer to an array of points that make up the vertices of the polygon.
The first two points in the array specify the first side of the polygon.
Each additional point specifies a new side, the vertices of which include the point and the previous point.
If the last point and the first point do not coincide, they specify the last side of the polygon.

### `count`

Integer that specifies the number of points in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example defines a polygon and then fills it.

```cpp
VOID Example_FillPolygon3(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Create an array of PointF objects that define the polygon.
   PointF point1(100.0f, 100.0f);
   PointF point2(200.0f, 130.0f);
   PointF point3(150.0f, 200.0f);
   PointF point4(50.0f, 200.0f);
   PointF point5(0.0f, 130.0f);
   PointF points[5] = {point1, point2, point3, point4, point5};

   // Fill the polygon.
   graphics.FillPolygon(&blackBrush, points, 5);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)