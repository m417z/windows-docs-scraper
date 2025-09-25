# Graphics::DrawArc(IN const Pen,IN const Rect &,IN REAL,IN REAL)

## Description

The **Graphics::DrawArc** method draws an arc. The arc is part of an ellipse.

## Parameters

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Pointer to a pen that is used to draw the arc.

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to the rectangle that bounds the ellipse that contains the arc.

### `startAngle` [in]

Type: **REAL**

Real number that specifies the angle between the x-axis and the starting point of the arc.

### `sweepAngle` [in]

Type: **REAL**

Real number that specifies the angle between the starting and ending points of the arc.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Creating Figures from Lines, Curves, and Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-figures-from-lines-curves-and-shapes-use)

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

[DrawEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawellipse(inconstpen_inconstrect_))

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)