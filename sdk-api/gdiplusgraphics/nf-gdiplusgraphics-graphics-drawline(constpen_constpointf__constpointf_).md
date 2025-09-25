# Graphics::DrawLine(IN const Pen,IN const PointF &,IN const PointF &)

## Description

The **Graphics::DrawLine** method draws a line that connects two points.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the line.

### `pt1` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object that specifies the start of the line.

### `pt2` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object that specifies the end of the line.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[DrawLines Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawlines(inconstpen_inconstpoint_inint))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)