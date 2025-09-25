# GetActiveWindow function

## Description

Retrieves the window handle to the active window attached to the calling thread's message queue.

## Return value

Type: **HWND**

The return value is the handle to the active window attached to the calling thread's message queue. Otherwise, the return value is **NULL**.

## Remarks

To get the handle to the foreground window, you can use [GetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getforegroundwindow).

To get the window handle to the active window in the message queue for another thread, use [GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo).

## See also

**Conceptual**

[GetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getforegroundwindow)

[GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**

[SetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setactivewindow)