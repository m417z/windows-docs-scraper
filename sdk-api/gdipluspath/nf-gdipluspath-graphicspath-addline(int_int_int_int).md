# GraphicsPath::AddLine(IN INT,IN INT,IN INT,IN INT)

## Description

The **GraphicsPath::AddLine** method adds a line to the current figure of this path.

## Parameters

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

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[AddLine Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addline(inconstpoint__inconstpoint_))

[AddLines Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addlines(inconstpoint_inint))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)