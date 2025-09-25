# EnumWindowStationsW function

## Description

Enumerates all window stations in the current session. The function passes the name of each window station, in turn, to an application-defined callback function.

## Parameters

### `lpEnumFunc` [in]

A pointer to an application-defined
[EnumWindowStationProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682643(v=vs.85)) callback function.

### `lParam` [in]

An application-defined value to be passed to the callback function.

## Return value

If the function succeeds, it returns the nonzero value returned by the callback function that was pointed to by *lpEnumFunc*.

If the function is unable to perform the enumeration, the return value is zero. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

If the callback function fails, the return value is zero. The callback function can call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set an error code for the caller to retrieve by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**EnumWindowStations** function enumerates only those window stations for which the calling process has the WINSTA_ENUMERATE access right. For more information, see
[Window Station Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/window-station-security-and-access-rights).

**EnumWindowStations** repeatedly invokes the *lpEnumFunc* callback function until the last window station is enumerated or the callback function returns FALSE.

> [!NOTE]
> The winuser.h header defines EnumWindowStations as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumWindowStationProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682643(v=vs.85))

[Window Station and Desktop Functions](https://learn.microsoft.com/windows/desktop/winstation/window-station-and-desktop-functions)

[Window Stations](https://learn.microsoft.com/windows/desktop/winstation/window-stations)