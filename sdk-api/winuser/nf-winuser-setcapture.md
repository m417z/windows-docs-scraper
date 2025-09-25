# SetCapture function

## Description

Sets the mouse capture to the specified window belonging to the current thread. **SetCapture** captures mouse input either when the mouse is over the capturing window, or when the mouse button was pressed while the mouse was over the capturing window and the button is still down. Only one window at a time can capture the mouse.

If the mouse cursor is over a window created by another thread, the system will direct mouse input to the specified window only if a mouse button is down.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window in the current thread that is to capture the mouse.

## Return value

Type: **HWND**

The return value is a handle to the window that had previously captured the mouse. If there is no such window, the return value is **NULL**.

## Remarks

Only the foreground window can capture the mouse. When a background window attempts to do so, the window receives messages only for mouse events that occur when the cursor hot spot is within the visible portion of the window. Also, even if the foreground window has captured the mouse, the user can still click another window, bringing it to the foreground.

When the window no longer requires all mouse input, the thread that created the window should call the [ReleaseCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasecapture) function to release the mouse.

This function cannot be used to capture mouse input meant for another process.

When the mouse is captured, menu hotkeys and other keyboard accelerators do not work.

#### Examples

For an example, see [Drawing Lines with the Mouse](https://learn.microsoft.com/windows/desktop/inputdev/using-mouse-input).

## See also

**Conceptual**

[GetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcapture)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**

[ReleaseCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasecapture)

[WM_CAPTURECHANGED](https://learn.microsoft.com/windows/desktop/inputdev/wm-capturechanged)