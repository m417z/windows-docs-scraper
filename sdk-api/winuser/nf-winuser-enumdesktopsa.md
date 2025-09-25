# EnumDesktopsA function

## Description

Enumerates all desktops associated with the specified window station of the calling process. The function passes the name of each desktop, in turn, to an application-defined callback function.

## Parameters

### `hwinsta` [in, optional]

A handle to the window station whose desktops are to be enumerated. This handle is returned by the
[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa),
[GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation), or
[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa) function, and must have the WINSTA_ENUMDESKTOPS access right. For more information, see
[Window Station Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/window-station-security-and-access-rights).

If this parameter is NULL, the current window station is used.

### `lpEnumFunc` [in]

A pointer to an application-defined
[EnumDesktopProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682612(v=vs.85)) callback function.

### `lParam` [in]

An application-defined value to be passed to the callback function.

## Return value

If the function succeeds, it returns the nonzero value returned by the callback function that was pointed to by *lpEnumFunc*.

If the function is unable to perform the enumeration, the return value is zero. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

If the callback function fails, the return value is zero. The callback function can call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set an error code for the caller to retrieve by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**EnumDesktops** function enumerates only those desktops for which the calling process has the DESKTOP_ENUMERATE access right. For more information, see
[Desktop Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights).

The
**EnumDesktops** function repeatedly invokes the *lpEnumFunc* callback function until the last desktop is enumerated or the callback function returns FALSE.

> [!NOTE]
> The winuser.h header defines EnumDesktops as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowstationa)

[Desktops](https://learn.microsoft.com/windows/desktop/winstation/desktops)

[EnumDesktopProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682612(v=vs.85))

[GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation)

[OpenWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openwindowstationa)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)