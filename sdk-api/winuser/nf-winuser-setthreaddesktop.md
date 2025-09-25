# SetThreadDesktop function

## Description

Assigns the specified desktop to the calling thread. All subsequent operations on the desktop use the access rights granted to the desktop.

## Parameters

### `hDesktop` [in]

A handle to the desktop to be assigned to the calling thread. This handle is returned by the
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa),
[GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop), [OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa), or
[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop) function.

This desktop must be associated with the current window station for the process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetThreadDesktop** function will fail if the calling thread has any windows or hooks on its current desktop (unless the *hDesktop* parameter is a handle to the current desktop).

**Warning** There is a significant security risk for any service that opens a window on the interactive desktop. By opening a desktop window, a service makes itself vulnerable to attack from the logged-on user, whose application could send malicious messages to the service's desktop window and affect its ability to function.

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)