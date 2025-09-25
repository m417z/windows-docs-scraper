# Graphics::DrawRectangle(IN const Pen,IN REAL,IN REAL,IN REAL,IN REAL)

## Description

The **Graphics::DrawRectangle** method draws a rectangle.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) that is used to draw the rectangle.

### `x` [in]

Type: **REAL**

Real number that specifies the x-coordinate of the upper-left corner of the rectangle.

### `y` [in]

Type: **REAL**

Real number that specifies the y-coordinate of the upper-left corner of the rectangle.

### `width` [in]

Type: **REAL**

Real number that specifies the width of the rectangle.

### `height` [in]

Type: **REAL**

Real number that specifies the height of the rectangle.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[DrawRectangles Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawrectangles(inconstpen_inconstrect_inint))

[FillRectangle Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)