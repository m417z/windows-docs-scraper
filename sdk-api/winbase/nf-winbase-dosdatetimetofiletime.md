# DosDateTimeToFileTime function

## Description

Converts MS-DOS date and time values to a file time.

## Parameters

### `wFatDate` [in]

The MS-DOS date. The date is a packed value with the following format.

| Bits | Description |
| --- | --- |
| 0-4 | Day of the month (1–31) |
| 5-8 | Month (1 = January, 2 = February, and so on) |
| 9-15 | Year offset from 1980 (add 1980 to get actual year) |

### `wFatTime` [in]

The MS-DOS time. The time is a packed value with the following format.

| Bits | Description |
| --- | --- |
| 0-4 | Second divided by 2 |
| 5-10 | Minute (0–59) |
| 11-15 | Hour (0–23 on a 24-hour clock) |

### `lpFileTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the converted file time.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-filetimetodosdatetime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)