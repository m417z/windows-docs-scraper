# GetCapture function

## Description

Retrieves a handle to the window (if any) that has captured the mouse. Only one window at a time can capture the mouse; this window receives mouse input whether or not the cursor is within its borders.

## Return value

Type: **HWND**

The return value is a handle to the capture window associated with the current thread. If no window in the thread has captured the mouse, the return value is **NULL**.

## Remarks

A **NULL** return value means the current thread has not captured the mouse. However, it is possible that another thread or process has captured the mouse.

To get a handle to the capture window on another thread, use the [GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo) function.

## See also

**Conceptual**

[GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**

[ReleaseCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasecapture)

[SetCapture](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcapture)