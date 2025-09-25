# CopyRect function

## Description

The **CopyRect** function copies the coordinates of one rectangle to another.

## Parameters

### `lprcDst` [out]

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the logical coordinates of the source rectangle.

### `lprcSrc` [in]

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure whose coordinates are to be copied in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[SetRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setrect)

[SetRectEmpty](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setrectempty)