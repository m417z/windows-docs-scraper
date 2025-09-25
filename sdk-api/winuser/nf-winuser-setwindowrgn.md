# SetWindowRgn function

## Description

The **SetWindowRgn** function sets the window region of a window. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region

## Parameters

### `hWnd` [in]

A handle to the window whose window region is to be set.

### `hRgn` [in]

A handle to a region. The function sets the window region of the window to this region.

If *hRgn* is **NULL**, the function sets the window region to **NULL**.

### `bRedraw` [in]

Specifies whether the system redraws the window after setting the window region. If *bRedraw* is **TRUE**, the system does so; otherwise, it does not.

Typically, you set *bRedraw* to **TRUE** if the window is visible.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

When this function is called, the system sends the [WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging) and [WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanged) messages to the window.

The coordinates of a window's window region are relative to the upper-left corner of the window, not the client area of the window.

**Note** If the window layout is right-to-left (RTL), the coordinates are relative to the upper-right corner of the window. See [Window Layout and Mirroring](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

After a successful call to **SetWindowRgn**, the system owns the region specified by the region handle *hRgn*. The system does not make a copy of the region. Thus, you should not make any further function calls with this region handle. In particular, do not delete this region handle. The system deletes the region handle when it no longer needed.

To obtain the window region of a window, call the [GetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowrgn) function.

## See also

[GetWindowRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowrgn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging)

[WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging)