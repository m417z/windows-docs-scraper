# ArrangeIconicWindows function

## Description

Arranges all the minimized (iconic) child windows of the specified parent window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the parent window.

## Return value

Type: **UINT**

If the function succeeds, the return value is the height of one row of icons.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application that maintains its own minimized child windows can use the **ArrangeIconicWindows** function to arrange icons in a parent window. This function can also arrange icons on the desktop. To retrieve the window handle to the desktop window, use the [GetDesktopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdesktopwindow) function.

An application sends the [WM_MDIICONARRANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-mdiiconarrange) message to the multiple-document interface (MDI) client window to prompt the client window to arrange its minimized MDI child windows.

## See also

[CloseWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindow)

**Conceptual**

[GetDesktopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdesktopwindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)