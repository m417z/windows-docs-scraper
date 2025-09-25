# GraphicsPath::AddPie

## Description

The **GraphicsPath::AddPie** method adds a pie to this path.
An arc is a portion of an ellipse, and a pie is a portion of the area enclosed by an ellipse.
A pie is bounded by an arc and two lines (edges) that go from the center of the ellipse to the endpoints of the arc.

## Parameters

### `rect`

Reference to a rectangle that bounds the ellipse that bounds the pie.

### `startAngle`

Real number that specifies the clockwise angle, in degrees, between the horizontal axis of the ellipse and the starting point of the arc that defines the pie.

### `sweepAngle`

Real number that specifies the clockwise angle, in degrees, between the starting and ending points of the arc that defines the pie.

## Return value

**Type:** [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object path, adds a pie to path, and then draws path.

```cpp
VOID Example_AddPie(HDC hdc)
{
   Graphics graphics(hdc);

   RectF rect(50.0f, 50.0f, 100.0f, 100.0f);

   GraphicsPath path;
   path.AddPie(rect, 20.0f, 45.0f);

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);

   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddArc Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addarc(inconstrect__inreal_inreal))

[AddPie Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addpie(inconstrect__inreal_inreal))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

[DrawPie Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpie(inconstpen_inconstrect__inreal_inreal))

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Open and Closed Curves](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-open-and-closed-curves-about)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)