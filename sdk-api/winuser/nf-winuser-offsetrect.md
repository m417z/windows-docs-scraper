# OffsetRect function

## Description

The **OffsetRect** function moves the specified rectangle by the specified offsets.

## Parameters

### `lprc` [in, out]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the rectangle to be moved.

### `dx` [in]

Specifies the amount to move the rectangle left or right. This parameter must be a negative value to move the rectangle to the left.

### `dy` [in]

Specifies the amount to move the rectangle up or down. This parameter must be a negative value to move the rectangle up.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[InflateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-inflaterect)

[IntersectRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-intersectrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[UnionRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unionrect)