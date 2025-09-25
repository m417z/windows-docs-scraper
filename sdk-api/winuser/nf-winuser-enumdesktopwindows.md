# EnumDesktopWindows function

## Description

Enumerates all top-level windows associated with the specified desktop. It passes the handle to each window, in turn, to an application-defined callback function.

## Parameters

### `hDesktop` [in, optional]

A handle to the desktop whose top-level windows are to be enumerated. This handle is returned by the
[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa),
[GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop), [OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa), or
[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop) function, and must have the **DESKTOP_READOBJECTS** access right. For more information, see
[Desktop Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights).

If this parameter is NULL, the current desktop is used.

### `lpfn` [in]

A pointer to an application-defined
[EnumWindowsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633498(v=vs.85)) callback function.

### `lParam` [in]

An application-defined value to be passed to the callback function.

## Return value

If the function fails or is unable to perform the enumeration, the return value is zero.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

You must ensure that the callback function sets [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) if it fails.

**Windows Server 2003 and Windows XP/2000:** If there are no windows on the desktop, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_HANDLE**.

## Remarks

The
**EnumDesktopWindows** function repeatedly invokes the *lpfn* callback function until the last top-level window is enumerated or the callback function returns **FALSE**.

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[EnumWindowsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms633498(v=vs.85))

[GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)