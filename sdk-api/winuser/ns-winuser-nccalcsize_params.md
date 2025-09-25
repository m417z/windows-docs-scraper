# NCCALCSIZE_PARAMS structure

## Description

Contains information that an application can use while processing the [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message to calculate the size, position, and valid contents of the client area of a window.

## Members

### `rgrc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)[3]**

An array of rectangles. The meaning of the array of rectangles changes during the processing of the [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message.

When the window procedure receives the [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message, the first rectangle contains the new coordinates of a window that has been moved or resized, that is, it is the proposed new window coordinates. The second contains the coordinates of the window before it was moved or resized. The third contains the coordinates of the window's client area before the window was moved or resized. If the window is a child window, the coordinates are relative to the client area of the parent window. If the window is a top-level window, the coordinates are relative to the screen origin.

When the window procedure returns, the first rectangle contains the coordinates of the new client rectangle resulting from the move or resize. The second rectangle contains the valid destination rectangle, and the third rectangle contains the valid source rectangle. The last two rectangles are used in conjunction with the return value of the [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message to determine the area of the window to be preserved.

### `lppos`

Type: **PWINDOWPOS**

A pointer to a [WINDOWPOS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowpos) structure that contains the size and position values specified in the operation that moved or resized the window.

## See also

**Conceptual**

[MoveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-movewindow)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[WINDOWPOS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowpos)

[WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)