# InflateRect function

## Description

The **InflateRect** function increases or decreases the width and height of the specified rectangle. The **InflateRect** function adds *-dx* units to the left end and *dx* to the right end of the rectangle and *-dy* units to the top and *dy* to the bottom. The *dx* and *dy* parameters are signed values; positive values increase the width and height, and negative values decrease them.

## Parameters

### `lprc` [in, out]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that increases or decreases in size.

### `dx` [in]

The amount to increase or decrease the rectangle width. This parameter must be negative to decrease the width.

### `dy` [in]

The amount to increase or decrease the rectangle height. This parameter must be negative to decrease the height.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

## See also

[IntersectRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-intersectrect)

[OffsetRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-offsetrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[UnionRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unionrect)