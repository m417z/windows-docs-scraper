# FileTimeToSystemTime function

## Description

Converts a file time to system time format. System time is based on Coordinated Universal Time (UTC).

## Parameters

### `lpFileTime` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the file
time to be converted to system (UTC) date and time format.

This value must be less than 0x8000000000000000. Otherwise, the function fails.

### `lpSystemTime` [out]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure to receive the
converted file time.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[DosDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dosdatetimetofiletime)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[FileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-filetimetodosdatetime)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)