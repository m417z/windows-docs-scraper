# ValidateRgn function

## Description

The **ValidateRgn** function validates the client area within a region by removing the region from the current update region of the specified window.

## Parameters

### `hWnd` [in]

Handle to the window whose update region is to be modified.

### `hRgn` [in]

Handle to a region that defines the area to be removed from the update region. If this parameter is **NULL**, the entire client area is removed.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The specified region must have been created by a region function. The region coordinates are assumed to be client coordinates.

The [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function automatically validates the entire client area. Neither the [ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect) nor **ValidateRgn** function should be called if a portion of the update region must be validated before the next [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message is generated.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[ExcludeUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-excludeupdatergn)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[ValidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-validaterect)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)