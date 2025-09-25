# SetRect function

## Description

The **SetRect** function sets the coordinates of the specified rectangle. This is equivalent to assigning the left, top, right, and bottom arguments to the appropriate members of the **RECT** structure.

## Parameters

### `lprc` [out]

Pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle to be set.

### `xLeft` [in]

Specifies the x-coordinate of the rectangle's upper-left corner.

### `yTop` [in]

Specifies the y-coordinate of the rectangle's upper-left corner.

### `xRight` [in]

Specifies the x-coordinate of the rectangle's lower-right corner.

### `yBottom` [in]

Specifies the y-coordinate of the rectangle's lower-right corner.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Because applications can use rectangles for different purposes, the rectangle functions do not use an explicit unit of measure. Instead, all rectangle coordinates and dimensions are given in signed, logical values. The mapping mode and the function in which the rectangle is used determine the units of measure.

#### Examples

For an example, see [Using Rectangles](https://learn.microsoft.com/windows/desktop/gdi/using-rectangles).

## See also

[CopyRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyrect)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Rectangle Functions](https://learn.microsoft.com/windows/desktop/gdi/rectangle-functions)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)

[SetRectEmpty](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setrectempty)