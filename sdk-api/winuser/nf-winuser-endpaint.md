# EndPaint function

## Description

The **EndPaint** function marks the end of painting in the specified window. This function is required for each call to the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function, but only after painting is complete.

## Parameters

### `hWnd` [in]

Handle to the window that has been repainted.

### `lpPaint` [in]

Pointer to a [PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct) structure that contains the painting information retrieved by [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint).

## Return value

The return value is always nonzero.

## Remarks

If the caret was hidden by [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint), **EndPaint** restores the caret to the screen.

**EndPaint** releases the display device context that [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) retrieved.

#### Examples

For an example, see [Drawing in the Client Area](https://learn.microsoft.com/windows/desktop/gdi/drawing-in-the-client-area).

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)