# SubtractRect function

## Description

The **SubtractRect** function determines the coordinates of a rectangle formed by subtracting one rectangle from another.

## Parameters

### `lprcDst` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the coordinates of the rectangle determined by subtracting the rectangle pointed to by *lprcSrc2* from the rectangle pointed to by *lprcSrc1*.

### `lprcSrc1` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure from which the function subtracts the rectangle pointed to by *lprcSrc2*.

### `lprcSrc2` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that the function subtracts from the rectangle pointed to by *lprcSrc1*.

## Return value

If the resulting rectangle is empty, the return value is zero.

If the resulting rectangle is not empty, the return value is nonzero.

## Remarks

The function only subtracts the rectangle specified by *lprcSrc2* from the rectangle specified by *lprcSrc1* when the rectangles intersect completely in either the x- or y-direction. For example, if **lprcSrc1* has the coordinates (10,10,100,100) and **lprcSrc2* has the coordinates (50,50,150,150), the function sets the coordinates of the rectangle pointed to by *lprcDst* to (10,10,100,100). If **lprcSrc1* has the coordinates (10,10,100,100) and **lprcSrc2* has the coordinates (50,10,150,150), however, the function sets the coordinates of the rectangle pointed to by *lprcDst* to (10,10,50,100). In other words, the resulting rectangle is the bounding box of the geometric difference.

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

## See also

[IntersectRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-intersectrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[UnionRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unionrect)