# GraphicsPath::AddArc(IN INT,IN INT,IN INT,IN INT,IN REAL,IN REAL)

## Description

The **GraphicsPath::AddArc** method adds an elliptical arc to the current figure of this path.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc.

### `width` [in]

Type: **INT**

Integer that specifies the width of the bounding rectangle for the ellipse that contains the arc.

### `height` [in]

Type: **INT**

Integer that specifies the height of the bounding rectangle for the ellipse that contains the arc.

### `startAngle` [in]

Type: **REAL**

Real number that specifies the clockwise angle, in degrees, between the horizontal axis of the ellipse and the starting point of the arc.

### `sweepAngle` [in]

Type: **REAL**

Real number that specifies the clockwise angle, in degrees, between the starting point (*startAngle*) and ending point of the arc.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[AddArc Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addarc(inconstrect__inreal_inreal))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[DrawArc Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawarc(inconstpen_inconstrectf__inreal_inreal))

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)