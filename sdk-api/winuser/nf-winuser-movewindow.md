# MoveWindow function

## Description

Changes the position and dimensions of the specified window. For a top-level window, the position and dimensions are relative to the upper-left corner of the screen. For a child window, they are relative to the upper-left corner of the parent window's client area.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `X` [in]

Type: **int**

The new position of the left side of the window.

### `Y` [in]

Type: **int**

The new position of the top of the window.

### `nWidth` [in]

Type: **int**

The new width of the window.

### `nHeight` [in]

Type: **int**

The new height of the window.

### `bRepaint` [in]

Type: **BOOL**

Indicates whether the window is to be repainted. If this parameter is **TRUE**, the window receives a message. If the parameter is **FALSE**, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of moving a child window.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *bRepaint* parameter is **TRUE**, the system sends the [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to the window procedure immediately after moving the window (that is, the **MoveWindow** function calls the [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) function). If *bRepaint* is **FALSE**, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing.

**MoveWindow** sends the [WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging), [WM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanged), [WM_MOVE](https://learn.microsoft.com/windows/desktop/winmsg/wm-move), [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size), and [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) messages to the window.

#### Examples

For an example, see [Creating, Enumerating, and Sizing Child Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

**Conceptual**

**Other Resources**

**Reference**

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)

[WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)