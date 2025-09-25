# EqualRect function

## Description

The **EqualRect** function determines whether the two specified rectangles are equal by comparing the coordinates of their upper-left and lower-right corners.

## Parameters

### `lprc1` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the first rectangle.

### `lprc2` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the second rectangle.

## Return value

If the two rectangles are identical, the return value is nonzero.

If the two rectangles are not identical, the return value is zero.

## Remarks

The **EqualRect** function does not treat empty rectangles as equal if their coordinates are different.

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

## See also

[IsRectEmpty](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isrectempty)

[PtInRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-ptinrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)