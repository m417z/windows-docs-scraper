# DrawFocusRect function

## Description

The **DrawFocusRect** function draws a rectangle in the style used to indicate that the rectangle has the focus.

## Parameters

### `hDC` [in]

A handle to the device context.

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the logical coordinates of the rectangle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

**DrawFocusRect** works only in MM_TEXT mode.

Because **DrawFocusRect** is an XOR function, calling it a second time with the same rectangle removes the rectangle from the screen.

This function draws a rectangle that cannot be scrolled. To scroll an area containing a rectangle drawn by this function, call **DrawFocusRect** to remove the rectangle from the screen, scroll the area, and then call **DrawFocusRect** again to draw the rectangle in the new position.

**Windows XP:** The focus rectangle can now be thicker than 1 pixel, so it is more visible for high-resolution, high-density displays and accessibility needs. This is handled by the SPI_SETFOCUSBORDERWIDTH and SPI_SETFOCUSBORDERHEIGHT in [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa).

#### Examples

For an example, see "Creating an Owner-Drawn List Box" in [Using List Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-list-boxes).

## See also

[FrameRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-framerect)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)