# DeferWindowPos function

## Description

Updates the specified multiple-window
– position structure for the specified window. The function then returns a handle to the updated structure. The [EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos) function uses the information in this structure to change the position and size of a number of windows simultaneously. The [BeginDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-begindeferwindowpos) function creates the structure.

## Parameters

### `hWinPosInfo` [in]

Type: **HDWP**

A handle to a multiple-window
– position structure that contains size and position information for one or more windows. This structure is returned by [BeginDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-begindeferwindowpos) or by the most recent call to **DeferWindowPos**.

### `hWnd` [in]

Type: **HWND**

A handle to the window for which update information is stored in the structure. All windows in a multiple-window
– position structure must have the same parent.

### `hWndInsertAfter` [in, optional]

Type: **HWND**

A handle to the window that precedes the positioned window in the Z order. This parameter must be a window handle or one of the following values. This parameter is ignored if the **SWP_NOZORDER** flag is set in the *uFlags* parameter.

| Value | Meaning |
| --- | --- |
| **HWND_BOTTOM**<br><br>((HWND)1) | Places the window at the bottom of the Z order. If the *hWnd* parameter identifies a topmost window, the window loses its topmost status and is placed at the bottom of all other windows. |
| **HWND_NOTOPMOST**<br><br>((HWND)-2) | Places the window above all non-topmost windows (that is, behind all topmost windows). This flag has no effect if the window is already a non-topmost window. |
| **HWND_TOP**<br><br>((HWND)0) | Places the window at the top of the Z order. |
| **HWND_TOPMOST**<br><br>((HWND)-1) | Places the window above all non-topmost windows. The window maintains its topmost position even when it is deactivated. |

### `x` [in]

Type: **int**

The x-coordinate of the window's upper-left corner.

### `y` [in]

Type: **int**

The y-coordinate of the window's upper-left corner.

### `cx` [in]

Type: **int**

The window's new width, in pixels.

### `cy` [in]

Type: **int**

The window's new height, in pixels.

### `uFlags` [in]

Type: **UINT**

A combination of the following values that affect the size and position of the window.

| Value | Meaning |
| --- | --- |
| **SWP_DRAWFRAME**<br><br>0x0020 | Draws a frame (defined in the window's class description) around the window. |
| **SWP_FRAMECHANGED**<br><br>0x0020 | Sends a [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize) message to the window, even if the window's size is not being changed. If this flag is not specified, **WM_NCCALCSIZE** is sent only when the window's size is being changed. |
| **SWP_HIDEWINDOW**<br><br>0x0080 | Hides the window. |
| **SWP_NOACTIVATE**<br><br>0x0010 | Does not activate the window. If this flag is not set, the window is activated and moved to the top of either the topmost or non-topmost group (depending on the setting of the *hWndInsertAfter* parameter). |
| **SWP_NOCOPYBITS**<br><br>0x0100 | Discards the entire contents of the client area. If this flag is not specified, the valid contents of the client area are saved and copied back into the client area after the window is sized or repositioned. |
| **SWP_NOMOVE**<br><br>0x0002 | Retains the current position (ignores the *x* and *y* parameters). |
| **SWP_NOOWNERZORDER**<br><br>0x0200 | Does not change the owner window's position in the Z order. |
| **SWP_NOREDRAW**<br><br>0x0008 | Does not redraw changes. If this flag is set, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of the window being moved. When this flag is set, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing. |
| **SWP_NOREPOSITION**<br><br>0x0200 | Same as the **SWP_NOOWNERZORDER** flag. |
| **SWP_NOSENDCHANGING**<br><br>0x0400 | Prevents the window from receiving the [WM_WINDOWPOSCHANGING](https://learn.microsoft.com/windows/desktop/winmsg/wm-windowposchanging) message. |
| **SWP_NOSIZE**<br><br>0x0001 | Retains the current size (ignores the *cx* and *cy* parameters). |
| **SWP_NOZORDER**<br><br>0x0004 | Retains the current Z order (ignores the *hWndInsertAfter* parameter). |
| **SWP_SHOWWINDOW**<br><br>0x0040 | Displays the window. |

## Return value

Type: **HDWP**

The return value identifies the updated multiple-window
– position structure. The handle returned by this function may differ from the handle passed to the function. The new handle that this function returns should be passed during the next call to the **DeferWindowPos** or [EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos) function.

If insufficient system resources are available for the function to succeed, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a call to **DeferWindowPos** fails, the application should abandon the window-positioning operation and not call [EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos).

If **SWP_NOZORDER** is not specified, the system places the window identified by the *hWnd* parameter in the position following the window identified by the *hWndInsertAfter* parameter. If *hWndInsertAfter* is **NULL** or **HWND_TOP**, the system places the *hWnd* window at the top of the Z order. If *hWndInsertAfter* is set to **HWND_BOTTOM**, the system places the *hWnd* window at the bottom of the Z order.

All coordinates for child windows are relative to the upper-left corner of the parent window's client area.

A window can be made a topmost window either by setting *hWndInsertAfter* to the **HWND_TOPMOST** flag and ensuring that the **SWP_NOZORDER** flag is not set, or by setting the window's position in the Z order so that it is above any existing topmost windows. When a non-topmost window is made topmost, its owned windows are also made topmost. Its owners, however, are not changed.

If neither the **SWP_NOACTIVATE** nor **SWP_NOZORDER** flag is specified (that is, when the application requests that a window be simultaneously activated and its position in the Z order changed), the value specified in *hWndInsertAfter* is used only in the following circumstances:

* Neither the **HWND_TOPMOST** nor **HWND_NOTOPMOST** flag is specified in *hWndInsertAfter*.
* The window identified by *hWnd* is not the active window.

An application cannot activate an inactive window without also bringing it to the top of the Z order. An application can change an activated window's position in the Z order without restrictions, or it can activate a window and then move it to the top of the topmost or non-topmost windows.

A topmost window is no longer topmost if it is repositioned to the bottom (**HWND_BOTTOM**) of the Z order or after any non-topmost window. When a topmost window is made non-topmost, its owners and its owned windows are also made non-topmost windows.

A non-topmost window may own a topmost window, but not vice versa. Any window (for example, a dialog box) owned by a topmost window is itself made a topmost window to ensure that all owned windows stay above their owner.

## See also

[BeginDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-begindeferwindowpos)

**Conceptual**

[EndDeferWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddeferwindowpos)

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)