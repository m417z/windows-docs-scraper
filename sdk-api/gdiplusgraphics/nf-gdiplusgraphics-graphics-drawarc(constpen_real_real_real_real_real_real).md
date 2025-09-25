# DrawArc(Pen*,REAL,REAL,REAL,REAL,REAL,REAL)

## Description

The **Graphics::DrawArc** method draws an arc.
The arc is part of an ellipse.

## Parameters

### `pen`

Pointer to a pen that is used to draw the arc.

### `x`

Real number that specifies the x-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc.

### `y`

Real number that specifies the y-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc.

### `width`

Real number that specifies the width of the ellipse that contains the arc.

### `height`

Real number that specifies the height of the ellipse that contains the arc.

### `startAngle`

Real number that specifies the angle between the x-axis and the starting point of the arc.

### `sweepAngle`

Real number that specifies the angle between the starting and ending points of the arc.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws a 90-degree arc.

```cpp
VOID Example_DrawArc4(HDC hdc)
{
   Graphics graphics(hdc);

   // Set up the arc.
   Pen redPen(Color(255, 255, 0, 0), 3);
   REAL x = 0;
   REAL y = 0;
   REAL width = 200.0f;
   REAL height = 100.0f;
   REAL startAngle = 0.0f;
   REAL sweepAngle = 90.0f;

   // Draw the arc.
   graphics.DrawArc(&redPen, x, y, width, height, startAngle, sweepAngle);
}
```

## See also

[Creating Figures from Lines, Curves, and Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-figures-from-lines-curves-and-shapes-use)

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

[DrawEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawellipse(inconstpen_inconstrect_))

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)