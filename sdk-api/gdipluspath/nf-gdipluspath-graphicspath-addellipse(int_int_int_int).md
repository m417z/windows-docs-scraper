# GraphicsPath::AddEllipse(IN INT,IN INT,IN INT,IN INT)

## Description

The **GraphicsPath::AddEllipse** method adds an ellipse to this path.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the bounding rectangle for the ellipse.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the bounding rectangle for the ellipse.

### `width` [in]

Type: **INT**

Integer that specifies the width of the bounding rectangle for the ellipse.

### `height` [in]

Type: **INT**

Integer that specifies the height of the bounding rectangle for the ellipse.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object stores an ellipse as a sequence of four connected Bézier splines. The **GraphicsPath** object does not store the upper-left corner, width, and height of the ellipse's bounding rectangle.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds an ellipse to *path*, and then draws *path*.

```cpp
VOID Example_AddEllipse(HDC hdc)
{
   Graphics graphics(hdc);

   GraphicsPath path;
   path.AddEllipse(20, 20, 200, 100);

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddArc Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addarc(inconstrect__inreal_inreal))

[AddEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addellipse(inconstrect_))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)