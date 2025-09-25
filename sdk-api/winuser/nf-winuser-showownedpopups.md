# ShowOwnedPopups function

## Description

Shows or hides all pop-up windows owned by the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window that owns the pop-up windows to be shown or hidden.

### `fShow` [in]

Type: **BOOL**

If this parameter is **TRUE**, all hidden pop-up windows are shown. If this parameter is **FALSE**, all visible pop-up windows are hidden.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**ShowOwnedPopups** shows only windows hidden by a previous call to **ShowOwnedPopups**. For example, if a pop-up window is hidden by using the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function, subsequently calling **ShowOwnedPopups** with the *fShow* parameter set to **TRUE** does not cause the window to be shown.

## See also

**Conceptual**

[IsWindowVisible](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowvisible)

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)