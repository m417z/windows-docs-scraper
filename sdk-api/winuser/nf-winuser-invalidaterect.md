# InvalidateRect function

## Description

The **InvalidateRect** function adds a rectangle to the specified window's update region. The update region represents the portion of the window's client area that must be redrawn.

## Parameters

### `hWnd` [in]

A handle to the window whose update region has changed. If this parameter is **NULL**, the system invalidates and redraws all windows, not just the windows for this application, and sends the [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) and [WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint) messages before the function returns. Setting this parameter to **NULL** is not recommended.

### `lpRect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the client coordinates of the rectangle to be added to the update region. If this parameter is **NULL**, the entire client area is added to the update region.

### `bErase` [in]

Specifies whether the background within the update region is to be erased when the update region is processed. If this parameter is **TRUE**, the background is erased when the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function is called. If this parameter is **FALSE**, the background remains unchanged.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The invalidated areas accumulate in the update region until the region is processed when the next [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message occurs or until the region is validated by using the [ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect) or [ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn) function.

The system sends a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to a window whenever its update region is not empty and there are no other messages in the application queue for that window.

If the *bErase* parameter is **TRUE** for any part of the update region, the background is erased in the entire region, not just in the specified part.

#### Examples

For an example, see [Invalidating the Client Area](https://learn.microsoft.com/windows/desktop/gdi/invalidating-the-client-area).

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect)

[ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn)

[WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd)

[WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)