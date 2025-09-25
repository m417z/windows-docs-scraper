# ITextHost::TxScrollWindowEx

## Description

Requests the text host to scroll the content of the specified client area.

## Parameters

### `dx` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Amount of horizontal scrolling.

### `dy` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Amount of vertical scrolling.

### `lprcScroll` [in]

Type: **LPCRECT**

The coordinates for the scroll rectangle.

### `lprcClip` [in]

Type: **LPCRECT**

The coordinates for the clip rectangle.

### `hrgnUpdate` [in]

Type: **[HRGN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the update region.

### `lprcUpdate` [in]

Type: **LPRECT**

The coordinates for the update rectangle.

### `fuScroll` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scrolling flags. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SW_ERASE** | Erases the newly invalidated region by sending a [WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message to the window when specified with the SW_INVALIDATE flag. |
| **SW_INVALIDATE** | Invalidates the region identified by the *hrgnUpdate* parameter after scrolling. |
| **SW_SCROLLCHILDREN** | Scrolls all child windows that intersect the rectangle pointed to by the *lprcScroll* parameter. The child windows are scrolled by the number of pixels specified by the *dx* and *dy* parameters. The system sends a [WM_MOVE](https://learn.microsoft.com/windows/desktop/winmsg/wm-move) message to all child windows that intersect the *lprcScroll* rectangle, even if they do not move. |
| **SW_SMOOTHSCROLL** | Scrolls using smooth scrolling. Use the [HIWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632657(v=vs.85)) portion of the *fuScroll* parameter to indicate how much time the smooth-scrolling operation should take. |

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)