# LockWindowUpdate function

## Description

The **LockWindowUpdate** function disables or enables drawing in the specified window. Only one window can be locked at a time.

## Parameters

### `hWndLock` [in]

The window in which drawing will be disabled. If this parameter is **NULL**, drawing in the locked window is enabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero, indicating that an error occurred or another window was already locked.

## Remarks

The purpose of the **LockWindowUpdate** function is to permit drag/drop feedback to be drawn over a window without interference from the window itself. The intent is that the window is locked when feedback is drawn and unlocked when feedback is complete. **LockWindowUpdate** is not intended for general-purpose suppression of window redraw. Use the [WM_SETREDRAW](https://learn.microsoft.com/windows/desktop/gdi/wm-setredraw) message to disable redrawing of a particular window.

If an application with a locked window (or any locked child windows) calls the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc), [GetDCEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdcex), or [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function, the called function returns a device context with a visible region that is empty. This will occur until the application unlocks the window by calling **LockWindowUpdate**, specifying a value of **NULL** for *hWndLock*.

If an application attempts to draw within a locked window, the system records the extent of the attempted operation in a bounding rectangle. When the window is unlocked, the system invalidates the area within this bounding rectangle, forcing an eventual [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to be sent to the previously locked window and its child windows. If no drawing has occurred while the window updates were locked, no area is invalidated.

**LockWindowUpdate** does not make the specified window invisible and does not clear the WS_VISIBLE style bit.

A locked window cannot be moved.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[GetDCEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdcex)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)