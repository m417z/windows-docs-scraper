# GetParent function

## Description

Retrieves a handle to the specified window's parent or owner.

To retrieve a handle to a specified ancestor, use the [GetAncestor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getancestor) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose parent window handle is to be retrieved.

## Return value

Type: **HWND**

If the window is a child window, the return value is a handle to the parent window. If the window is a top-level window with the **WS_POPUP** style, the return value is a handle to the owner window.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function typically fails for one of the following reasons:

* The window is a top-level window that is unowned or does not have the **WS_POPUP** style.
* The owner window has **WS_POPUP** style.

## Remarks

To obtain a window's owner window, instead of using **GetParent**, use [GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow) with the **GW_OWNER** flag. To obtain the parent window and not the owner, instead of using **GetParent**, use [GetAncestor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getancestor) with the **GA_PARENT** flag.

#### Examples

For an example, see [Initializing a Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[GetAncestor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getancestor)

[GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow)

**Reference**

[SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)

[Windows Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles)