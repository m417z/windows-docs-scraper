# BeginPaint function

## Description

The **BeginPaint** function prepares the specified window for painting and fills a [PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct) structure with information about the painting.

## Parameters

### `hWnd` [in]

Handle to the window to be repainted.

### `lpPaint` [out]

Pointer to the [PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct) structure that will receive painting information.

## Return value

If the function succeeds, the return value is the handle to a display device context for the specified window.

If the function fails, the return value is **NULL**, indicating that no display device context is available.

## Remarks

The **BeginPaint** function automatically sets the clipping region of the device context to exclude any area outside the update region. The update region is set by the [InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect) or [InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn) function and by the system after sizing, moving, creating, scrolling, or any other operation that affects the client area. If the update region is marked for erasing, **BeginPaint** sends a **WM_ERASEBKGND** message to the window.

An application should not call **BeginPaint** except in response to a **WM_PAINT** message. Each call to **BeginPaint** must have a corresponding call to the [EndPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-endpaint) function.

If the caret is in the area to be painted, **BeginPaint** automatically hides the caret to prevent it from being erased.

If the window's class has a background brush, **BeginPaint** uses that brush to erase the background of the update region before returning.

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is always in terms of physical pixels.

#### Examples

For an example, see [Drawing in the Client Area](https://learn.microsoft.com/windows/desktop/gdi/drawing-in-the-client-area).

## See also

[EndPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-endpaint)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect)

[ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn)