# GetTimeZoneInformation function

## Description

Retrieves the current time zone settings. These settings control the translations between Coordinated Universal Time (UTC) and local time.

To support boundaries for daylight saving time that change from year to year, use the [GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation) or [GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear) function.

## Parameters

### `lpTimeZoneInformation` [out]

A pointer to a
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure to receive the current settings.

## Return value

If the function succeeds, it returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **TIME_ZONE_ID_UNKNOWN**<br><br>0 | Daylight saving time is not used in the current time zone, because there are no transition dates or automatic adjustment for daylight saving time is disabled. |
| **TIME_ZONE_ID_STANDARD**<br><br>1 | The system is operating in the range covered by the **StandardDate** member of the [TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure. <br><br> |
| **TIME_ZONE_ID_DAYLIGHT**<br><br>2 | The system is operating in the range covered by the **DaylightDate** member of the [TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure. |

If the function fails for other reasons, such as an out of memory error, it returns TIME_ZONE_ID_INVALID. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All translations between UTC time and local time are based on the following formula:

UTC = local time + bias

The bias is the difference, in minutes, between UTC time and local time.

 The **StandardName** and **DaylightName** members of the resultant [TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information) structure are localized according to the current user default UI language.

#### Examples

For an example, see [SetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-settimezoneinformation).

## See also

[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)

[GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear)

[Local Time](https://learn.microsoft.com/windows/desktop/SysInfo/local-time)

[SetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-settimezoneinformation)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)