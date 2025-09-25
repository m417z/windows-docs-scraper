# SetFocus function

## Description

Sets the keyboard focus to the specified window. The window must be attached to the calling thread's message queue.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window that will receive the keyboard input. If this parameter is NULL, keystrokes are ignored.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the window that previously had the keyboard focus. If the *hWnd* parameter is invalid or the window is not attached to the calling thread's message queue, the return value is NULL. To get extended error information, call [GetLastError function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Extended error ERROR_INVALID_PARAMETER (0x57) means that window is in disabled state.

## Remarks

This function sends a [WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus) message to the window that loses the keyboard focus and a [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) message to the window that receives the keyboard focus. It also activates either the window that receives the focus or the parent of the window that receives the focus.

If a window is active but does not have the focus, any key pressed produces the [WM_SYSCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-syschar), [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown), or [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup) message. If the VK_MENU key is also pressed, bit 30 of the *lParam* parameter of the message is set. Otherwise, the messages produced do not have this bit set.

By using the [AttachThreadInput function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-attachthreadinput), a thread can attach its input processing to another thread. This allows a thread to call SetFocus to set the keyboard focus to a window attached to another thread's message queue.

### Examples

For an example, see [Initializing a Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

[AttachThreadInput function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-attachthreadinput), [GetFocus function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getfocus), [WM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-killfocus), [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus), [WM_SYSCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-syschar), [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown), [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup), [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)