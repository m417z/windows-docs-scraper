# SetActiveWindow function

## Description

Activates a window. The window must be attached to the calling thread's message queue.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the top-level window to be activated.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the window that was previously active.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetActiveWindow** function activates a window, but not if the application is in the background. The window will be brought into the foreground (top of [Z-Order](https://learn.microsoft.com/windows/desktop/winmsg/window-features)) if its application is in the foreground when the system activates the window.

If the window identified by the
*hWnd* parameter was created by the calling thread, the active window status of the calling thread is set to
*hWnd*. Otherwise, the active window status of the calling thread is set to **NULL**.

## See also

**Conceptual**

[GetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getactivewindow)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)

[WM_ACTIVATE](https://learn.microsoft.com/windows/desktop/inputdev/wm-activate)