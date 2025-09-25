# WINDOWPOS structure

## Description

Contains information about the size and position of a window.

## Members

### `hwndInsertAfter`

Type: **HWND**

The position of the window in Z order (front-to-back position). This member can be a handle to the window behind which this window is placed, or can be one of the special values listed with the [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos) function.

### `hwnd`

Type: **HWND**

A handle to the window.

### `x`

Type: **int**

The position of the left edge of the window.

### `y`

Type: **int**

The position of the top edge of the window.

### `cx`

Type: **int**

The window width, in pixels.

### `cy`

Type: **int**

The window height, in pixels.

### `flags`

Type: **UINT**

The window position. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SWP_DRAWFRAME**<br><br>0x0020 | Draws a frame (defined in the window's class description) around the window. Same as the **SWP_FRAMECHANGED** flag. |
| **SWP_FRAMECHANGED**<br><br>0x0020 | Sends a [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message to the window, even if the window's size is not being changed. If this flag is not specified, **WM_NCCALCSIZE** is sent only when the window's size is being changed. |
| **SWP_HIDEWINDOW**<br><br>0x0080 | Hides the window. |
| **SWP_NOACTIVATE**<br><br>0x0010 | Does not activate the window. If this flag is not set, the window is activated and moved to the top of either the topmost or non-topmost group (depending on the setting of the **hwndInsertAfter** member). |
| **SWP_NOCOPYBITS**<br><br>0x0100 | Discards the entire contents of the client area. If this flag is not specified, the valid contents of the client area are saved and copied back into the client area after the window is sized or repositioned. |
| **SWP_NOMOVE**<br><br>0x0002 | Retains the current position (ignores the **x** and **y** members). |
| **SWP_ NOOWNERZORDER**<br><br>0x0200 | Does not change the owner window's position in the Z order. |
| **SWP_NOREDRAW**<br><br>0x0008 | Does not redraw changes. If this flag is set, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of the window being moved. When this flag is set, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing. |
| **SWP_NOREPOSITION**<br><br>0x0200 | Does not change the owner window's position in the Z order. Same as the **SWP_NOOWNERZORDER** flag. |
| **SWP_NOSENDCHANGING**<br><br>0x0400 | Prevents the window from receiving the [WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging) message. |
| **SWP_NOSIZE**<br><br>0x0001 | Retains the current size (ignores the **cx** and **cy** members). |
| **SWP_NOZORDER**<br><br>0x0004 | Retains the current Z order (ignores the **hwndInsertAfter** member). |
| **SWP_SHOWWINDOW**<br><br>0x0040 | Displays the window. |

## See also

**Conceptual**

[EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos)

**Reference**

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)