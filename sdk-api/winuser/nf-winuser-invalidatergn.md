# InvalidateRgn function

## Description

The **InvalidateRgn** function invalidates the client area within the specified region by adding it to the current update region of a window. The invalidated region, along with all other areas in the update region, is marked for painting when the next [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message occurs.

## Parameters

### `hWnd` [in]

A handle to the window with an update region that is to be modified.

### `hRgn` [in]

A handle to the region to be added to the update region. The region is assumed to have client coordinates. If this parameter is **NULL**, the entire client area is added to the update region.

### `bErase` [in]

Specifies whether the background within the update region should be erased when the update region is processed. If this parameter is **TRUE**, the background is erased when the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function is called. If the parameter is **FALSE**, the background remains unchanged.

## Return value

The return value is always nonzero.

## Remarks

Invalidated areas accumulate in the update region until the next [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message is processed or until the region is validated by using the [ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect) or [ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn) function.

The system sends a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to a window whenever its update region is not empty and there are no other messages in the application queue for that window.

The specified region must have been created by using one of the region functions.

If the *bErase* parameter is **TRUE** for any part of the update region, the background in the entire region is erased, not just in the specified part.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect)

[ValidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validatergn)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)