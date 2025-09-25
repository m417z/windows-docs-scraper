# DrawPolygon(Pen*,PointF*,INT*)

## Description

The **Graphics::DrawPolygon** method draws a polygon.

## Parameters

### `pen`

Pointer to a pen that is used to draw the polygon.

### `points`

Pointer to an array of [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the vertices of the polygon.

### `count`

Integer that specifies the number of elements in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

If the first and last coordinates in the *points* array are not identical, a line is drawn between them to close the polygon.

#### Examples

The following example draws a polygon, defined by an array of points.

```cpp
VOID Example_DrawPolygon2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Create an array of PointF objects that define the polygon.
   PointF point1(100.0f, 100.0f);
   PointF point2(200.0f, 130.0f);
   PointF point3(150.0f, 200.0f);
   PointF point4(50.0f, 200.0f);
   PointF point5(0.0f, 130.0f);
   PointF points[5] = {point1, point2, point3, point4, point5};
   PointF* pPoints = points;

   // Draw the polygon.
   graphics.DrawPolygon(&blackPen, pPoints, 5);
}
```

## See also

[FillPolygon Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpolygon(inconstbrush_inconstpointf_inint_infillmode))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[Polygons](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-polygons-about)