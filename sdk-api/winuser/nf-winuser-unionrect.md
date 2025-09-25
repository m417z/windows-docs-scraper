# UnionRect function

## Description

The **UnionRect** function creates the union of two rectangles. The union is the smallest rectangle that contains both source rectangles.

## Parameters

### `lprcDst` [out]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that will receive a rectangle containing the rectangles pointed to by the *lprcSrc1* and *lprcSrc2* parameters.

### `lprcSrc1` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the first source rectangle.

### `lprcSrc2` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the second source rectangle.

## Return value

If the specified structure contains a nonempty rectangle, the return value is nonzero.

If the specified structure does not contain a nonempty rectangle, the return value is zero.

## Remarks

The system ignores the dimensions of an empty rectangle that is, a rectangle in which all coordinates are set to zero, so that it has no height or no width.

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

## See also

[InflateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-inflaterect)

[IntersectRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-intersectrect)

[OffsetRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-offsetrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)