# OpenIcon function

## Description

Restores a minimized (iconic) window to its previous size and position; it then activates the window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be restored and activated.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**OpenIcon** sends a [WM_QUERYOPEN](https://learn.microsoft.com/windows/desktop/winmsg/wm-queryopen) message to the given window.

## See also

[CloseWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindow)

**Conceptual**

[IsIconic](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isiconic)

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)