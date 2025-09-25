# Graphics::DrawLines(IN const Pen,IN const Point,IN INT)

## Description

The **Graphics::DrawLines** method draws a sequence of connected lines.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the lines.

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the starting and ending points of the lines.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
**Status** enumeration.

## Remarks

Each line requires a starting point and an ending point. The ending point of each line is the starting point for the next.

#### Examples

The following example draws a sequence of connected lines.

```cpp

VOID Example_DrawLines(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Create an array of Point objects that define the lines to draw.
   Point point1(10, 10);
   Point point2(10, 100);
   Point point3(200, 50);
   Point point4(250, 300);

   Point points[4] = {point1, point2, point3, point4};
   Point* pPoints = points;

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