# TzSpecificLocalTimeToSystemTime function

## Description

Converts a local time to a time in Coordinated Universal Time (UTC).

## Parameters

### `lpTimeZoneInformation` [in, optional]

A pointer to a
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure that specifies the time zone for the time specified in *lpLocalTime*.

If *lpTimeZoneInformation* is **NULL**, the function uses the currently active time zone.

### `lpLocalTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the local time to be converted. The function converts this time to the corresponding UTC time.

### `lpUniversalTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the UTC time.

## Return value

If the function succeeds, the return value is nonzero, and the function sets the members of the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure pointed to by *lpUniversalTime* to the appropriate values.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**TzSpecificLocalTimeToSystemTime** takes into account whether daylight saving time (DST) is in effect for the local time to be converted.

## See also

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SystemTimeToTzSpecificLocalTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetotzspecificlocaltime)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)