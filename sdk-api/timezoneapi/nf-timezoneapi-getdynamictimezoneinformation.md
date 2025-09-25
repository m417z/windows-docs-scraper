# GetDynamicTimeZoneInformation function

## Description

Retrieves the current time zone and dynamic daylight saving time settings. These settings control the translations between Coordinated Universal Time (UTC) and local time.

## Parameters

### `pTimeZoneInformation` [out]

A pointer to a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure.

## Return value

If the function succeeds, it returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **TIME_ZONE_ID_UNKNOWN**<br><br>0 | Daylight saving time is not used in the current time zone, because there are no transition dates. |
| **TIME_ZONE_ID_STANDARD**<br><br>1 | The system is operating in the range covered by the **StandardDate** member of the [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure. <br><br> |
| **TIME_ZONE_ID_DAYLIGHT**<br><br>2 | The system is operating in the range covered by the **DaylightDate** member of the [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure. |

If the function fails, it returns TIME_ZONE_ID_INVALID. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 The **StandardName** and **DaylightName** members of the resultant [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure are localized according to the current user default UI language.

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)