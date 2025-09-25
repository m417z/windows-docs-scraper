# Graphics::DrawLine(IN const Pen,IN INT,IN INT,IN INT,IN INT)

## Description

The **Graphics::DrawLine** method draws a line that connects two points.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the line.

### `x1` [in]

Type: **INT**

Integer that specifies the x-coordinate of the starting point of the line.

### `y1` [in]

Type: **INT**

Integer that specifies the y-coordinate of the starting point of the line.

### `x2` [in]

Type: **INT**

Integer that specifies the x-coordinate of the ending point of the line.

### `y2` [in]

Type: **INT**

Integer that specifies the y-coordinate of the ending point of the line.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
**Status** enumeration.

## See also

[DrawLines Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawlines(inconstpen_inconstpoint_inint))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)