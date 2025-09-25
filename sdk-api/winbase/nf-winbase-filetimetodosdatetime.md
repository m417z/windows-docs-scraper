# FileTimeToDosDateTime function

## Description

Converts a file time to MS-DOS date and time values.

## Parameters

### `lpFileTime` [in]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the file time to convert to MS-DOS date and time format.

### `lpFatDate` [out]

A pointer to a variable to receive the MS-DOS date. The date is a packed value with the following format.

| Bits | Description |
| --- | --- |
| 0–4 | Day of the month (1–31) |
| 5–8 | Month (1 = January, 2 = February, etc.) |
| 9-15 | Year offset from 1980 (add 1980 to get actual year) |

### `lpFatTime` [out]

A pointer to a variable to receive the MS-DOS time. The time is a packed value with the following format.

| Bits | Description |
| --- | --- |
| 0–4 | Second divided by 2 |
| 5–10 | Minute (0–59) |
| 11–15 | Hour (0–23 on a 24-hour clock) |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The MS-DOS date format can represent only dates between 1/1/1980 and 12/31/2107; this conversion fails if the input file time is outside this range.

## See also

[DosDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dosdatetimetofiletime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)