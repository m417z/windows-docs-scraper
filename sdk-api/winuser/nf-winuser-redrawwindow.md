# RedrawWindow function

## Description

The **RedrawWindow** function updates the specified rectangle or region in a window's client area.

## Parameters

### `hWnd` [in]

A handle to the window to be redrawn. If this parameter is **NULL**, the desktop window is updated.

### `lprcUpdate` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates, in device units, of the update rectangle. This parameter is ignored if the *hrgnUpdate* parameter identifies a region.

### `hrgnUpdate` [in]

A handle to the update region. If both the *hrgnUpdate* and *lprcUpdate* parameters are **NULL**, the entire client area is added to the update region.

### `flags` [in]

One or more redraw flags. This parameter can be used to invalidate or validate a window, control repainting, and control which windows are affected by **RedrawWindow**.

The following flags are used to invalidate the window.

| Flag (invalidation) | Description |
| --- | --- |
| **RDW_ERASE** | Causes the window to receive a [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message when the window is repainted. The RDW_INVALIDATE flag must also be specified; otherwise, RDW_ERASE has no effect. |
| **RDW_FRAME** | Causes any part of the nonclient area of the window that intersects the update region to receive a [WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint) message. The RDW_INVALIDATE flag must also be specified; otherwise, RDW_FRAME has no effect. The **WM_NCPAINT** message is typically not sent during the execution of **RedrawWindow** unless either RDW_UPDATENOW or RDW_ERASENOW is specified. |
| **RDW_INTERNALPAINT** | Causes a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to be posted to the window regardless of whether any portion of the window is invalid. |
| **RDW_INVALIDATE** | Invalidates *lprcUpdate* or *hrgnUpdate* (only one may be non-**NULL**). If both are **NULL**, the entire window is invalidated. |

The following flags are used to validate the window.

| Flag (validation) | Description |
| --- | --- |
| **RDW_NOERASE** | Suppresses any pending [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) messages. |
| **RDW_NOFRAME** | Suppresses any pending [WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint) messages. This flag must be used with RDW_VALIDATE and is typically used with RDW_NOCHILDREN. RDW_NOFRAME should be used with care, as it could cause parts of a window to be painted improperly. |
| **RDW_NOINTERNALPAINT** | Suppresses any pending internal [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages. This flag does not affect **WM_PAINT** messages resulting from a non-**NULL** update area. |
| **RDW_VALIDATE** | Validates *lprcUpdate* or *hrgnUpdate* (only one may be non-**NULL**). If both are **NULL**, the entire window is validated. This flag does not affect internal [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages. |

The following flags control when repainting occurs. **RedrawWindow** will not repaint unless one of these flags is specified.

| Flag | Description |
| --- | --- |
| **RDW_ERASENOW** | Causes the affected windows (as specified by the RDW_ALLCHILDREN and RDW_NOCHILDREN flags) to receive [WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint) and [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) messages, if necessary, before the function returns. [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages are received at the ordinary time. |
| **RDW_UPDATENOW** | Causes the affected windows (as specified by the RDW_ALLCHILDREN and RDW_NOCHILDREN flags) to receive [WM_NCPAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-ncpaint), [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd), and [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) messages, if necessary, before the function returns. |

By default, the windows affected by **RedrawWindow** depend on whether the specified window has the WS_CLIPCHILDREN style. Child windows that are not the WS_CLIPCHILDREN style are unaffected; non-WS_CLIPCHILDREN windows are recursively validated or invalidated until a WS_CLIPCHILDREN window is encountered. The following flags control which windows are affected by the **RedrawWindow** function.

| Flag | Description |
| --- | --- |
| **RDW_ALLCHILDREN** | Includes child windows, if any, in the repainting operation. |
| **RDW_NOCHILDREN** | Excludes child windows, if any, from the repainting operation. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

When **RedrawWindow** is used to invalidate part of the desktop window, the desktop window does not receive a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message. To repaint the desktop, an application uses the RDW_ERASE flag to generate a [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message.

## See also

[GetUpdateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdaterect)

[GetUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdatergn)

[InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect)

[InvalidateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)