# GetTimeZoneInformationForYear function

## Description

Retrieves the time zone settings for the specified year and time zone. These settings control the translations between Coordinated Universal Time (UTC) and local time.

## Parameters

### `wYear` [in]

The year for which the time zone settings are to be retrieved. The *wYear* parameter must be a local time value.

### `pdtzi` [in, optional]

A pointer to a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure that specifies the time zone. To populate this parameter, call [EnumDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-enumdynamictimezoneinformation) with the index of the time zone you want. If this parameter is **NULL**, the current time zone is used.

### `ptzi` [out]

A pointer to a [TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure that receives the time zone settings.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The *wYear* parameter is assumed to be a local time value. If the local time is close to the transition between the old year and the new year (00:00:00 January 1), passing a UTC year to the **GetTimeZoneInformationForYear** function can cause the function to return time zone settings for the wrong year.

 The **StandardName** and **DaylightName** members of the resultant [TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure are localized according to the current user default UI language.

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)