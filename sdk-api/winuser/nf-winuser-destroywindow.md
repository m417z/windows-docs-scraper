# DestroyWindow function

## Description

Destroys the specified window. The function sends [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) and [WM_NCDESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncdestroy) messages to the window to deactivate it and remove the keyboard focus from it. The function also destroys the window's menu, destroys timers, removes clipboard ownership, and breaks the clipboard viewer chain (if the window is at the top of the viewer chain).

If the specified window is a parent or owner window, **DestroyWindow** automatically destroys the associated child or owned windows when it destroys the parent or owner window. The function first destroys child or owned windows, and then it destroys the parent or owner window.

**DestroyWindow** also destroys modeless dialog boxes created by the [CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be destroyed.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A thread cannot use **DestroyWindow** to destroy a window created by a different thread.

If the window being destroyed is a child window that does not have the **WS_EX_NOPARENTNOTIFY** style, a [WM_PARENTNOTIFY](https://learn.microsoft.com/windows/win32/inputmsg/wm-parentnotify) message is sent to the parent.

#### Examples

For an example, see [Destroying a Window](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

**Conceptual**

[CreateDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialoga)

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

**Reference**

[WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy)

[WM_NCDESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncdestroy)

[WM_PARENTNOTIFY](https://learn.microsoft.com/windows/win32/inputmsg/wm-parentnotify)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)