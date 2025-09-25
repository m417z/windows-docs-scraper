# PtInRect function

## Description

The **PtInRect** function determines whether the specified point lies within the specified rectangle. A point is within a rectangle if it lies on the left or top side or is within all four sides. A point on the right or bottom side is considered outside the rectangle.

## Parameters

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the specified rectangle.

### `pt` [in]

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the specified point.

## Return value

If the specified point lies within the rectangle, the return value is nonzero.

If the specified point does not lie within the rectangle, the return value is zero.

## Remarks

The rectangle must be normalized before **PtInRect** is called. That is, lprc.right must be greater than lprc.left and lprc.bottom must be greater than lprc.top. If the rectangle is not normalized, a point is never considered inside of the rectangle.

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[EqualRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-equalrect)

[IsRectEmpty](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isrectempty)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)