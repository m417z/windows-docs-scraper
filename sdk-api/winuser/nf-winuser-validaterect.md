# ValidateRect function

## Description

The **ValidateRect** function validates the client area within a rectangle by removing the rectangle from the update region of the specified window.

## Parameters

### `hWnd` [in]

Handle to the window whose update region is to be modified. If this parameter is **NULL**, the system invalidates and redraws all windows and sends the **WM_ERASEBKGND** and **WM_NCPAINT** messages to the window procedure before the function returns.

### `lpRect` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the client coordinates of the rectangle to be removed from the update region. If this parameter is **NULL**, the entire client area is removed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function automatically validates the entire client area. Neither the **ValidateRect** nor [ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn) function should be called if a portion of the update region must be validated before the next [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message is generated.

The system continues to generate [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages until the current update region is validated.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)