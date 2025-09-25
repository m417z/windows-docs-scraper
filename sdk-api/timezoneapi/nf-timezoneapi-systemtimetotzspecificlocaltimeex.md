# SystemTimeToTzSpecificLocalTimeEx function

## Description

Converts a time in Coordinated Universal Time (UTC) with dynamic daylight saving time settings to a specified time zone's corresponding local time.

## Parameters

### `lpTimeZoneInformation` [in, optional]

A pointer to a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure that specifies the time zone and dynamic daylight saving time.

### `lpUniversalTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the UTC time to be converted. The function converts this universal time to the specified time zone's corresponding local time.

### `lpLocalTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the local time.

## Return value

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).