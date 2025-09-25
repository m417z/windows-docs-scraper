# IsRectEmpty function

## Description

The **IsRectEmpty** function determines whether the specified rectangle is empty. An empty rectangle is one that has no area; that is, the coordinate of the right side is less than or equal to the coordinate of the left side, or the coordinate of the bottom side is less than or equal to the coordinate of the top side.

## Parameters

### `lprc` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the rectangle.

## Return value

If the rectangle is empty, the return value is nonzero.

If the rectangle is not empty, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[EqualRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-equalrect)

[PtInRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ptinrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)