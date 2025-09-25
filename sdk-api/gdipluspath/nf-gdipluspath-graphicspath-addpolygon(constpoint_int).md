# GraphicsPath::AddPolygon(IN const Point,IN INT)

## Description

The **GraphicsPath::AddPolygon** method adds a polygon to this path.

## Parameters

### `points` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of points that specifies the vertices of the polygon.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **GraphicsPath::AddPolygon** method is similar to the **AddLines** method. The difference is that a polygon is an intrinsically closed figure, but a sequence of lines is not a closed figure unless you call [GraphicsPath::CloseFigure](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-closefigure). When Windows GDI+ renders a path, each polygon in that path is closed; that is, the last vertex of the polygon is connected to the first vertex by a straight line.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds a polygon to *path*, and then draws *path*.

```cpp
VOID Example_AddPolygon(HDC hdc)
{
   Graphics graphics(hdc);

   Point pts[] = {Point(20, 20),
                  Point(120, 20),
                  Point(120, 70)};

   GraphicsPath path;
   path.AddPolygon(pts, 3);

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddPolygon Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addpolygon(inconstpoint_inint))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Polygons](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-polygons-about)