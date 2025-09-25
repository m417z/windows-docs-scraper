# EndTask function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Forcibly closes the
specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be closed.

### `fShutDown` [in]

Type: **BOOL**

Ignored. Must be **FALSE**.

### `fForce` [in]

Type: **BOOL**

A **TRUE** for this parameter will force the destruction of the
window if an initial attempt fails to gently close the window using [WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close).
With a **FALSE** for this parameter, only the close with **WM_CLOSE** is attempted.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is **FALSE**.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function was not included in the SDK headers and libraries until Windows XP with Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

[CloseWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindow)

**Conceptual**

[DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow)

**Reference**

[WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)