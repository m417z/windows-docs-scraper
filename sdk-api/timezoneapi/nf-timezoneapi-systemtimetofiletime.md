# SystemTimeToFileTime function

## Description

Converts a system time to file time format. System time is based on Coordinated Universal Time (UTC).

## Parameters

### `lpSystemTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the system time to be converted from UTC to file time format.

The **wDayOfWeek** member of the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure is ignored.

### `lpFileTime` [out]

A pointer to a
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to receive the converted system time.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

> [!NOTE]
> A False return value can indicate that the passed SYSTEMTIME structure represents an invalid date. Certain situations, such as the additional day added in a leap year, can result in application logic unexpectedly creating an invalid date. For more information on avoiding these issues, see [leap year readiness](https://techcommunity.microsoft.com/t5/azure-developer-community-blog/it-s-2020-is-your-code-ready-for-leap-day/ba-p/1157279).

## See also

[DosDateTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dosdatetimetofiletime)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[FileTimeToDosDateTime](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-filetimetodosdatetime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)