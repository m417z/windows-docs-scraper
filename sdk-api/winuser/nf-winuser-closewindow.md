# CloseWindow function

## Description

Minimizes (but does not destroy) the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be minimized.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To destroy a window, an application must use the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function.

## See also

[ArrangeIconicWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-arrangeiconicwindows)

**Conceptual**

[DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow)

[IsIconic](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isiconic)

[OpenIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openicon)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)