# GraphicsPath::AddLines

## Description

The **GraphicsPath::AddLines** method adds a sequence of connected lines to the current figure of this path.

## Parameters

### `points`

Pointer to an array of points that specify the starting and ending points of the lines.
The first point in the array is the starting point of the first line, and the last point in the array is the ending point of the last line.
Each of the other points serves as ending point for one line and starting point for the next line.

### `count`

Integer that specifies the number of elements in the points array.

## Return value

**Type:** [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object path, adds a sequence of four connected lines to path, and then draws path.

```cpp
VOID Example_AddLines(HDC hdc)
{
   Graphics graphics(hdc);

   PointF pts[] = {PointF(20.0f, 20.0f),
                   PointF(30.0f, 30.0f),
                   PointF(40.0f, 25.0f),
                   PointF(50.0f, 30.0f),
                   PointF(60.0f, 20.0f)};

   GraphicsPath path;
   path.AddLines(pts, 5);

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddLine Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addline(inconstpoint__inconstpoint_))

[AddLines Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addlines(inconstpoint_inint))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)