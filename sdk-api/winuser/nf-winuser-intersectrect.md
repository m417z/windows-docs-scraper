# IntersectRect function

## Description

The **IntersectRect** function calculates the intersection of two source rectangles and places the coordinates of the intersection rectangle into the destination rectangle. If the source rectangles do not intersect, an empty rectangle (in which all coordinates are set to zero) is placed into the destination rectangle.

## Parameters

### `lprcDst` [out]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that is to receive the intersection of the rectangles pointed to by the *lprcSrc1* and *lprcSrc2* parameters. This parameter cannot be **NULL**.

### `lprcSrc1` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the first source rectangle.

### `lprcSrc2` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the second source rectangle.

## Return value

If the rectangles intersect, the return value is nonzero.

If the rectangles do not intersect, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[InflateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-inflaterect)

[OffsetRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-offsetrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[UnionRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unionrect)