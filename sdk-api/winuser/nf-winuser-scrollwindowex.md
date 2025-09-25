# ScrollWindowEx function

## Description

The **ScrollWindowEx** function scrolls the contents of the specified window's client area.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window where the client area is to be scrolled.

### `dx` [in]

Type: **int**

Specifies the amount, in device units, of horizontal scrolling. This parameter must be a negative value to scroll to the left.

### `dy` [in]

Type: **int**

Specifies the amount, in device units, of vertical scrolling. This parameter must be a negative value to scroll up.

### `prcScroll` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the portion of the client area to be scrolled. If this parameter is **NULL**, the entire client area is scrolled.

### `prcClip` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a
[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the coordinates of the clipping rectangle. Only device bits within the clipping rectangle are affected. Bits scrolled from the outside of the rectangle to the inside are painted; bits scrolled from the inside of the rectangle to the outside are not painted. This parameter may be **NULL**.

### `hrgnUpdate` [in]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the region that is modified to hold the region invalidated by scrolling. This parameter may be **NULL**.

### `prcUpdate` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the boundaries of the rectangle invalidated by scrolling. This parameter may be **NULL**.

### `flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies flags that control scrolling. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SW_ERASE** | Erases the newly invalidated region by sending a [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message to the window when specified with the SW_INVALIDATE flag. |
| **SW_INVALIDATE** | Invalidates the region identified by the *hrgnUpdate* parameter after scrolling. |
| **SW_SCROLLCHILDREN** | Scrolls all child windows that intersect the rectangle pointed to by the *prcScroll* parameter. The child windows are scrolled by the number of pixels specified by the *dx* and *dy* parameters. The system sends a [WM_MOVE](https://learn.microsoft.com/windows/desktop/winmsg/wm-move) message to all child windows that intersect the *prcScroll* rectangle, even if they do not move. |
| **SW_SMOOTHSCROLL** | Scrolls using smooth scrolling. Use the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) portion of the *flags* parameter to indicate how much time, in milliseconds, the smooth-scrolling operation should take. |

## Return value

Type: **int**

If the function succeeds, the return value is SIMPLEREGION (rectangular invalidated region), COMPLEXREGION (nonrectangular invalidated region; overlapping rectangles), or NULLREGION (no invalidated region).

If the function fails, the return value is ERROR. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the SW_INVALIDATE and SW_ERASE flags are not specified, **ScrollWindowEx** does not invalidate the area that is scrolled from. If either of these flags is set, **ScrollWindowEx** invalidates this area. The area is not updated until the application calls the [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) function, calls the [RedrawWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-redrawwindow) function (specifying the RDW_UPDATENOW or RDW_ERASENOW flag), or retrieves the
[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message from the application queue.

If the window has the [WS_CLIPCHILDREN](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style, the returned areas specified by
*hrgnUpdate* and
*prcUpdate* represent the total area of the scrolled window that must be updated, including any areas in child windows that need updating.

If the SW_SCROLLCHILDREN flag is specified, the system does not properly update the screen if part of a child window is scrolled. The part of the scrolled child window that lies outside the source rectangle is not erased and is not properly redrawn in its new destination. To move child windows that do not lie completely within the rectangle specified by
*prcScroll*, use the [DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos) function. The cursor is repositioned if the SW_SCROLLCHILDREN flag is set and the caret rectangle intersects the scroll rectangle.

All input and output coordinates (for
*prcScroll*,
*prcClip*,
*prcUpdate*, and
*hrgnUpdate*) are determined as client coordinates, regardless of whether the window has the [CS_OWNDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) or [CS_CLASSDC](https://learn.microsoft.com/windows/desktop/winmsg/window-class-styles) class style. Use the
[LPtoDP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lptodp) and
[DPtoLP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-dptolp) functions to convert to and from logical coordinates, if necessary.

#### Examples

For an example, see [Scrolling Text with the WM_PAINT Message](https://learn.microsoft.com/windows/desktop/Controls/using-scroll-bars).

## See also

[DPtoLP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-dptolp)

[DeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deferwindowpos)

[LPtoDP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lptodp)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[RedrawWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-redrawwindow)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)