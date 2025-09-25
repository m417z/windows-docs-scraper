# DrawLine(Pen*,REAL,REAL,REAL,REAL)

## Description

The **Graphics::DrawLine** method draws a line that connects two points.

## Parameters

### `pen`

Pointer to a pen that is used to draw the line.

### `x1`

Real number that specifies the x-coordinate of the starting point of the line.

### `y1`

Real number that specifies the y-coordinate of the starting point of the line.

### `x2`

Real number that specifies the x-coordinate of the ending point of the line.

### `y2`

Real number that specifies the y-coordinate of the ending point of the line.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws a line.

```cpp
VOID Example_DrawLine4(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen blackPen(Color(255, 0, 0, 0), 3);

   // Initialize the coordinates of the points that define the line.
   REAL x1 = 100.0f;
   REAL y1 = 100.0f;
   REAL x2 = 500.0f;
   REAL y2 = 100.0f;

   // Draw the line.
   graphics.DrawLine(&blackPen, x1, y1, x2, y2);
}
```

## See also

[DrawLines Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawlines(inconstpen_inconstpoint_inint))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)