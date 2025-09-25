# Graphics::DrawPolygon(IN const Pen,IN const Point,IN INT)

## Description

The **Graphics::DrawPolygon** method draws a polygon.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the polygon.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the vertices of the polygon.

### `count` [in]

Type: **INT***

Integer that specifies the number of elements in the
*points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If the first and last coordinates in the
*points* array are not identical, a line is drawn between them to close the polygon.

#### Examples

The following example draws a polygon, defined by an array of points.

```cpp
VOID Example_DrawPolygon(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Create an array of Point objects that define the polygon.
   Point point1(100, 100);
   Point point2(200, 130);
   Point point3(150, 200);
   Point point4(50, 200);
   Point point5(0, 130);
   Point points[5] = {point1, point2, point3, point4, point5};
   Point* pPoints = points;

   // Draw the polygon.
   graphics.DrawPolygon(&blackPen, pPoints, 5);
}
```

## See also

[FillPolygon Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpolygon(inconstbrush_inconstpointf_inint_infillmode))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Polygons](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-polygons-about)