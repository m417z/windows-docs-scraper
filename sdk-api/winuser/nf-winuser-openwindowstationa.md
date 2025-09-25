# OpenWindowStationA function

## Description

Opens the specified window station.

## Parameters

### `lpszWinSta` [in]

The name of the window station to be opened. Window station names are case-insensitive.

This window station must belong to the current session.

### `fInherit` [in]

If this value is **TRUE**, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `dwDesiredAccess` [in]

The access to the window station. For a list of access rights, see
[Window Station Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/window-station-security-and-access-rights).

## Return value

If the function succeeds, the return value is the handle to the specified window station.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After you are done with the handle, you must call
[CloseWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindowstation) to free the handle.

> [!NOTE]
> The winuser.h header defines OpenWindowStation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closewindowstation)

[ExitWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindows)

[ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex)

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)