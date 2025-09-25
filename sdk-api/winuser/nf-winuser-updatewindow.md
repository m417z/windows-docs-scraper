# UpdateWindow function

## Description

The **UpdateWindow** function updates the client area of the specified window by sending a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to the window if the window's update region is not empty. The function sends a **WM_PAINT** message directly to the window procedure of the specified window, bypassing the application queue. If the update region is empty, no message is sent.

## Parameters

### `hWnd` [in]

Handle to the window to be updated.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[ExcludeUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-excludeupdatergn)

[GetUpdateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdaterect)

[GetUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdatergn)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)