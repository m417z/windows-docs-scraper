# GraphicsPath::AddArc

## Description

The **GraphicsPath::AddArc** method adds an elliptical arc to the current figure of this path.

## Parameters

### `rect`

Reference to a rectangle that bounds the ellipse that contains the arc.

### `startAngle`

Real number that specifies the clockwise angle, in degrees, between the horizontal axis of the ellipse and the starting point of the arc.

### `sweepAngle`

Real number that specifies the clockwise angle, in degrees, between the starting point (startAngle) and the ending point of the arc.

## Return value

**Type:** [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds an arc to *path*, closes the arc, and then draws *path*.

```cpp
VOID AddArcExample(HDC hdc)
{
   Graphics graphics(hdc);
   RectF rect(20.0f, 20.0f, 50.0f, 100.0f);

   GraphicsPath path;
   path.AddArc(rect, 0.0f, 180.0f);
   path.CloseFigure();

   // Draw the path.
   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddArc Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addarc(inconstrect__inreal_inreal))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)