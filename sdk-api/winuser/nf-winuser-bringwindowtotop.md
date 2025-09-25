# BringWindowToTop function

## Description

Brings the specified window to the top of the Z order. If the window is a top-level window, it is activated. If the window is a child window, the top-level parent window associated with the child window is activated.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to bring to the top of the Z order.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use the **BringWindowToTop** function to uncover any window that is partially or completely obscured by other windows.

Calling this function is similar to calling the [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos) function to change a window's position in the Z order. **BringWindowToTop** does not make a window a top-level window.

## See also

**Conceptual**

**Reference**

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)