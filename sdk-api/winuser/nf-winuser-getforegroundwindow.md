# GetForegroundWindow function

## Description

Retrieves a handle to the foreground window (the window with which the user is currently working). The system assigns a slightly higher priority to the thread that creates the foreground window than it does to other threads.

## Return value

Type: **HWND**

The return value is a handle to the foreground window. The foreground window can be **NULL** in certain circumstances, such as when a window is losing activation.

## See also

**Conceptual**

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)