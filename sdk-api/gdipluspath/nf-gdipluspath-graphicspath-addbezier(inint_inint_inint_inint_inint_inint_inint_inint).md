# GraphicsPath::AddBezier(IN INT,IN INT,IN INT,IN INT,IN INT,IN INT,IN INT,IN INT)

## Description

The **GraphicsPath::AddBezier** method adds a Bézier spline to the current figure of this path.

## Parameters

### `x1` [in]

Type: **INT**

Integer that specifies the x-coordinate of the starting point of the Bézier spline.

### `y1` [in]

Type: **INT**

Integer that specifies the y-coordinate of the starting point of the Bézier spline.

### `x2` [in]

Type: **INT**

Integer that specifies the x-coordinate of the first control point of the Bézier spline.

### `y2` [in]

Type: **INT**

Integer that specifies the y-coordinate of the first control point of the Bézier spline.

### `x3` [in]

Type: **INT**

Integer that specifies the x-coordinate of the second control point of the Bézier spline.

### `y3` [in]

Type: **INT**

Integer that specifies the y-coordinate of the second control point of the Bézier spline.

### `x4` [in]

Type: **INT**

Integer that specifies the x-coordinate of the ending point of the Bézier spline.

### `y4` [in]

Type: **INT**

Integer that specifies the y-coordinate of the ending point of the Bézier spline.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[AddBezier Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbezier(inconstpoint__inconstpoint__inconstpoint__inconstpoint_))

[AddBeziers Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addbeziers(inconstpoint_inint))

[AddCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addcurve(inconstpointf_inint_inint_inint_inreal))

[Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-bezier-splines-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Drawing Bézier Splines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-bezier-splines-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)