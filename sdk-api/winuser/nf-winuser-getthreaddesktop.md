# GetThreadDesktop function

## Description

Retrieves a handle to the desktop assigned to the specified thread.

## Parameters

### `dwThreadId` [in]

The thread identifier. The
[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid) and
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) functions return thread identifiers.

## Return value

If the function succeeds, the return value is a handle to the desktop associated with the specified thread. You do not need to call the
[CloseDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closedesktop) function to close the returned handle.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system associates a desktop with a thread when that thread is created. A thread can use the
[SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop) function to change its desktop. The desktop associated with a thread must be on the window station associated with the thread's process.

The calling process can use the returned handle in calls to the
[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa), [GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity),
[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa), and [SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity) functions.

A service application is created with an associated window station and desktop, so there is no need to call a USER or GDI function to connect the service to a window station and desktop.

## See also

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation)

[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa)

[GetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectsecurity)

[SetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocesswindowstation)

[SetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddesktop)

[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa)

[SetUserObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectsecurity)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)