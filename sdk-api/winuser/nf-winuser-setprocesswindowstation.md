# SetProcessWindowStation function

## Description

Assigns the specified window station to the calling process. This enables the process to access objects in the window station such as desktops, the clipboard, and global atoms. All subsequent operations on the window station use the access rights granted to *hWinSta*.

## Parameters

### `hWinSta` [in]

A handle to the window station. This can be a handle returned by the
[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa),
[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa), or
[GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation) function.

This window station must be associated with the current session.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa)

[GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation)

[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa)

[SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)