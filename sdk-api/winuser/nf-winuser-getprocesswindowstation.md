# GetProcessWindowStation function

## Description

Retrieves a handle to the current window station for the calling process.

## Return value

If the function succeeds, the return value is a handle to the window station.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system associates a window station with a process when the process is created. A process can use the
[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation) function to change its window station.

The calling process can use the returned handle in calls to the
[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa), [GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity),
[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa), and [SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity) functions.

Do not close the handle returned by this function.

A service application is created with an associated window station and desktop, so there is no need to call a USER or GDI function to connect the service to a window station and desktop.

## See also

[GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop)

[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)