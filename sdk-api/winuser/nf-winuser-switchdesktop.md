# SwitchDesktop function

## Description

Makes the specified desktop visible and activates it. This enables the desktop to receive input from the user. The calling process must have DESKTOP_SWITCHDESKTOP access to the desktop for the
**SwitchDesktop** function to succeed.

## Parameters

### `hDesktop` [in]

A handle to the desktop. This handle is returned by the
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa) and
[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa) functions.

This desktop must be associated with the current window station for the process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). However,
**SwitchDesktop** only sets the last error for the following cases:

* When the desktop belongs to an invisible window station
* When *hDesktop* is an invalid handle, refers to a destroyed desktop, or belongs to a different session than that of the calling process

## Remarks

The
**SwitchDesktop** function fails if the desktop belongs to an invisible window station.
**SwitchDesktop** also fails when called from a process that is associated with a secured desktop such as the WinLogon and ScreenSaver desktops. Processes that are associated with a secured desktop include custom UserInit processes. Such calls typically fail with an "access denied" error.

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)