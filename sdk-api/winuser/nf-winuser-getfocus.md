# GetFocus function

## Description

Retrieves the handle to the window that has the keyboard focus, if the window is attached to the calling thread's message queue.

## Return value

Type: **HWND**

The return value is the handle to the window with the keyboard focus. If the calling thread's message queue does not have an associated window with the keyboard focus, the return value is **NULL**.

## Remarks

**GetFocus** returns the window with the keyboard focus for the current thread's message queue. If **GetFocus** returns **NULL**, another thread's queue may be attached to a window that has the keyboard focus.

Use the [GetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getforegroundwindow) function to retrieve the handle to the window with which the user is currently working. You can associate your thread's message queue with the windows owned by another thread by using the
[AttachThreadInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-attachthreadinput) function.

To get the window with the keyboard focus on the foreground queue or the queue of another thread, use the [GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo) function.

#### Examples

For an example, see "Creating a Combo Box Toolbar" in [Using Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-combo-boxes).

## See also

[AttachThreadInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-attachthreadinput)

**Conceptual**

[GetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getforegroundwindow)

[GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Other Resources**

**Reference**

[SetFocus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setfocus)

[WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus)

[WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus)