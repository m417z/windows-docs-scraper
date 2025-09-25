# InvertRect function

## Description

The **InvertRect** function inverts a rectangle in a window by performing a logical NOT operation on the color values for each pixel in the rectangle's interior.

## Parameters

### `hDC` [in]

A handle to the device context.

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the logical coordinates of the rectangle to be inverted.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

On monochrome screens, **InvertRect** makes white pixels black and black pixels white. On color screens, the inversion depends on how colors are generated for the screen. Calling **InvertRect** twice for the same rectangle restores the display to its previous colors.

## See also

[FillRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-fillrect)

[Filled Shape Functions](https://learn.microsoft.com/windows/desktop/gdi/filled-shape-functions)

[Filled Shapes Overview](https://learn.microsoft.com/windows/desktop/gdi/filled-shapes)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)