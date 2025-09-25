# TzSpecificLocalTimeToSystemTimeEx function

## Description

Converts a local time to a time with dynamic daylight saving time settings to Coordinated Universal Time (UTC).

## Parameters

### `lpTimeZoneInformation` [in, optional]

A pointer to a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure that specifies the time zone and dynamic daylight saving time.

### `lpLocalTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the local time to be converted. The function converts this time to the corresponding UTC time.

### `lpUniversalTime` [out]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that receives the UTC time.

## Return value

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).