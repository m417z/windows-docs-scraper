# DrawLines(Pen*,PointF*,INT)

## Description

The **Graphics::DrawLines** method draws a sequence of connected lines.

## Parameters

### `pen`

Pointer to a pen that is used to draw the lines.

### `points`

Pointer to an array of [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the starting and ending points of the lines.

### `count`

Integer that specifies the number of elements in the *points* array.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws a sequence of connected lines.

```cpp
VOID Example_DrawLines2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Create an array of PointF objects that define the lines to draw.
   PointF point1(10.0f, 10.0f);
   PointF point2(10.0f, 100.0f);
   PointF point3(200.0f, 50.0f);
   PointF point4(250.0f, 300.0f);

   PointF points[4] = {point1, point2, point3, point4};
   PointF* pPoints = points;

   // Draw the lines.
   graphics.DrawLines(&blackPen, pPoints, 4);
}
```

## See also

[DrawLine Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawline(inconstpen_inconstpointf__inconstpointf_))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)