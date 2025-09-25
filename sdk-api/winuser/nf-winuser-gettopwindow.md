# GetTopWindow function

## Description

Examines the Z order of the child windows associated with the specified parent window and retrieves a handle to the child window at the top of the Z order.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the parent window whose child windows are to be examined. If this parameter is **NULL**, the function returns a handle to the window at the top of the Z order.

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the child window at the top of the Z order. If the specified window has no child windows, the return value is **NULL**. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

**Conceptual**

[GetNextWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getnextwindow)

[GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)