# TIME_ZONE_INFORMATION structure

## Description

Specifies settings for a time zone.

## Members

### `Bias`

The current bias for local time translation on this computer, in minutes. The bias is the difference, in minutes, between Coordinated Universal Time (UTC) and local time. All translations between UTC and local time are based on the following formula:

UTC = local time + bias

This member is required.

### `StandardName`

A description for standard time. For example, "EST" could indicate Eastern Standard Time. The string will be returned unchanged by the
[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation) function. This string can be empty.

### `StandardDate`

A
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains a date and local time when the transition from daylight saving time to standard time occurs on this operating system. If the time zone does not support daylight saving time or if the caller needs to disable daylight saving time, the **wMonth** member in the
**SYSTEMTIME** structure must be zero. If this date is specified, the **DaylightDate** member of this structure must also be specified.

Otherwise, the system assumes the time zone data is invalid and no changes will be applied.

To select the correct day in the month, set the **wYear** member to zero, the **wHour** and **wMinute** members to the transition time, the **wDayOfWeek** member to the appropriate weekday, and the **wDay** member to indicate the occurrence of the day of the week within the month (1 to 5, where 5 indicates the final occurrence during the month if that day of the week does not occur 5 times).

Using this notation, specify 02:00 on the first Sunday in April as follows: **wHour** = 2, **wMonth** = 4, **wDayOfWeek** = 0, **wDay** = 1. Specify 02:00 on the last Thursday in October as follows: **wHour** = 2, **wMonth** = 10, **wDayOfWeek** = 4, **wDay** = 5.

If the **wYear** member is not zero, the transition date is absolute; it will only occur one time. Otherwise, it is a relative date that occurs yearly.

### `StandardBias`

The bias value to be used during local time translations that occur during standard time. This member is ignored if a value for the **StandardDate** member is not supplied.

This value is added to the value of the **Bias** member to form the bias used during standard time. In most time zones, the value of this member is zero.

### `DaylightName`

A description for daylight saving time. For example, "PDT" could indicate Pacific Daylight Time. The string will be returned unchanged by the
[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation) function. This string can be empty.

### `DaylightDate`

A
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains a date and local time when the transition from standard time to daylight saving time occurs on this operating system. If the time zone does not support daylight saving time or if the caller needs to disable daylight saving time, the **wMonth** member in the
**SYSTEMTIME** structure must be zero. If this date is specified, the **StandardDate** member in this structure must also be specified.

Otherwise, the system assumes the time zone data is invalid and no changes will be applied.

To select the correct day in the month, set the **wYear** member to zero, the **wHour** and **wMinute** members to the transition time, the **wDayOfWeek** member to the appropriate weekday, and the **wDay** member to indicate the occurrence of the day of the week within the month (1 to 5, where 5 indicates the final occurrence during the month if that day of the week does not occur 5 times).

If the **wYear** member is not zero, the transition date is absolute; it will only occur one time. Otherwise, it is a relative date that occurs yearly.

### `DaylightBias`

The bias value to be used during local time translations that occur during daylight saving time. This member is ignored if a value for the **DaylightDate** member is not supplied.

This value is added to the value of the **Bias** member to form the bias used during daylight saving time. In most time zones, the value of this member is –60.

## Remarks

Settings for each time zone are stored in the following registry key:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows NT
            CurrentVersion
               Time Zones
                  time_zone_name
```

Each time zone entry includes the following registry values.

| Registry value | Type | Description |
| --- | --- | --- |
| **Display** | REG_SZ | The display name. |
| **Dlt** | REG_SZ | The description for daylight time. |
| **MUI_Display** | REG_SZ | The display name as a string of the form @*path*,*-stringID*[;*comment*]. For more information, see [MUI](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface). |
| **MUI_Dlt** | REG_SZ | The description for daylight time as a string of the form @*path*,*-stringID*[;*comment*]. |
| **MUI_Std** | REG_SZ | The description for standard time as a string of the form @*path*,*-stringID*[;*comment*]. |
| **Std** | REG_SZ | The description for standard time. |
| **TZI** | REG_BINARY | The following time zone information.<br><br>``` syntax typedef struct _REG_TZI_FORMAT { LONG Bias; LONG StandardBias; LONG DaylightBias; SYSTEMTIME StandardDate; SYSTEMTIME DaylightDate; } REG_TZI_FORMAT;<br><br>``` |

For more information about the **Dynamic DST** key, see [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information).

 Both **StandardName** and **DaylightName** are localized according to the current user default UI language.

#### Examples

For an example, see [SetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-settimezoneinformation).

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[GetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-settimezoneinformation)