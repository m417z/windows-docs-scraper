# SystemTimeToTzSpecificLocalTime function

## Description

Converts a time in Coordinated Universal Time (UTC) to a specified time zone's corresponding local time.

## Parameters

### `lpTimeZoneInformation` [in, optional]

A pointer to a
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure that specifies the time zone of interest.

If *lpTimeZone* is **NULL**, the function uses the currently active time zone.

### `lpUniversalTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the UTC time to be converted. The function converts this universal time to the specified time zone's corresponding local time.

### `lpLocalTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the local time.

## Return value

If the function succeeds, the return value is nonzero, and the function sets the members of the
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure pointed to by *lpLocalTime* to the appropriate local time values.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SystemTimeToTzSpecificLocalTime** function takes into account whether daylight saving time (DST) is in effect for the local time to which the system time is to be converted.

The **SystemTimeToTzSpecificLocalTime** function may calculate the local time incorrectly under the following conditions:

* The time zone uses a different UTC offset for the old and new years.
* The UTC time to be converted and the calculated local time are in different years.

#### Examples

For an example, see [Retrieving the Last-Write Time](https://learn.microsoft.com/windows/desktop/SysInfo/retrieving-the-last-write-time).

## See also

[GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime)

[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)

[TzSpecificLocalTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-tzspecificlocaltimetosystemtime)