# DYNAMIC_TIME_ZONE_INFORMATION structure

## Description

Specifies settings for a time zone and dynamic daylight saving time.

## Members

### `Bias`

The current bias for local time translation on this computer, in minutes. The bias is the difference, in
minutes, between Coordinated Universal Time (UTC) and local time. All translations between UTC and local time
are based on the following formula:

UTC = local time + bias

This member is required.

### `StandardName`

A description for standard time. For example, "EST" could indicate Eastern Standard Time. The string will
be returned unchanged by the
[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)
function. This string can be empty.

### `StandardDate`

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains a date and
local time when the transition from daylight saving time to standard time occurs on this operating system. If
the time zone does not support daylight saving time or if the caller needs to disable daylight saving time, the
**wMonth** member in the
**SYSTEMTIME** structure must be zero. If this date is
specified, the **DaylightDate** member of this structure must also be specified.
Otherwise, the system assumes the time zone data is invalid and no changes will be applied.

To select the correct day in the month, set the **wYear** member to zero, the
**wHour** and **wMinute** members to the transition time, the
**wDayOfWeek** member to the appropriate weekday, and the
**wDay** member to indicate the occurrence of the day of the week within the month (1 to
5, where 5 indicates the final occurrence during the month if that day of the week does not occur 5 times).

Using this notation, specify 02:00 on the first Sunday in April as follows:
**wHour** = 2, **wMonth** = 4,
**wDayOfWeek** = 0, **wDay** = 1. Specify 02:00 on the last
Thursday in October as follows: **wHour** = 2, **wMonth** = 10,
**wDayOfWeek** = 4, **wDay** = 5.

If the
**wYear** member is not zero, the transition date is absolute; it will only occur one
time. Otherwise, it is a relative date that occurs yearly.

### `StandardBias`

The bias value to be used during local time translations that occur during standard time. This member is
ignored if a value for the **StandardDate** member is not supplied.

This value is added to the value of the **Bias** member to form the bias used during
standard time. In most time zones, the value of this member is zero.

### `DaylightName`

A description for daylight saving time (DST). For example, "PDT" could indicate Pacific Daylight Time. The
string will be returned unchanged by the
[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)
function. This string can be empty.

### `DaylightDate`

A [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains a
date and local time when the transition from standard time to daylight saving time occurs on this operating
system. If the time zone does not support daylight saving time or if the caller needs to disable daylight
saving time, the **wMonth** member in the
**SYSTEMTIME** structure must be zero. If this date is
specified, the **StandardDate** member in this structure must also be specified.
Otherwise, the system assumes the time zone data is invalid and no changes will be applied.

To select the correct day in the month, set the **wYear** member to zero, the
**wHour** and **wMinute** members to the transition time, the
**wDayOfWeek** member to the appropriate weekday, and the
**wDay** member to indicate the occurrence of the day of the week within the month (1 to
5, where 5 indicates the final occurrence during the month if that day of the week does not occur 5 times).

If the **wYear** member is not zero, the transition date is absolute; it will only
occur one time. Otherwise, it is a relative date that occurs yearly.

### `DaylightBias`

The bias value to be used during local time translations that occur during daylight saving time. This member
is ignored if a value for the **DaylightDate** member is not supplied.

This value is added to the value of the **Bias** member to form the bias used during
daylight saving time. In most time zones, the value of this member is –60.

### `TimeZoneKeyName`

The name of the time zone registry key on the local computer. For more information, see Remarks.

### `DynamicDaylightTimeDisabled`

Indicates whether dynamic daylight saving time is disabled. Setting this member to **TRUE** disables dynamic
daylight saving time, causing the system to use a fixed set of transition dates.

To restore dynamic daylight saving time, call the
[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation)
function with **DynamicDaylightTimeDisabled** set to **FALSE**.
The system will read the transition dates for the current year at the next time update, the next system reboot,
or the end of the calendar year (whichever comes first.)

When calling the
[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)
function, this member is **TRUE** if the time zone was set using the
[SetTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-settimezoneinformation) function instead of
[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation) or if
the user has disabled this feature using the Date and Time application in Control
Panel.

To disable daylight saving time, set this member to **TRUE**, clear the
**StandardDate** and **DaylightDate** members, and call
[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation). To
restore daylight saving time, call
**SetDynamicTimeZoneInformation** with
**DynamicDaylightTimeDisabled** set to **FALSE**.

## Remarks

Dynamic daylight saving time provides support for time zones whose boundaries for daylight saving time change
from year to year. This feature enables easier updating of systems, especially for locales where the yearly DST
boundaries are known in advance. After the time zone has been updated, the current time zone setting is applied to
all time operations, even when the time in question occurred before the time zone changed. Therefore, it is best
to store UTC times and convert them to the current local time zone.

You can set the transition dates for the current year using the
[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation) function.
To set future transition dates, you must add entries to the registry data. The settings for dynamic daylight time
are stored in the following registry key:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows NT
            CurrentVersion
               Time Zones
                  time_zone_name
                     Dynamic DST
```

Each **Dynamic DST** key includes the following registry values.

| Registry value | Type | Description |
| --- | --- | --- |
| **FirstEntry** | **REG_DWORD** | The first year in the table. |
| **LastEntry** | **REG_DWORD** | The last year in the table. |
| *year1* | **REG_BINARY** | The following time zone information.<br><br>``` syntax typedef struct _REG_TZI_FORMAT { LONG Bias; LONG StandardBias; LONG DaylightBias; SYSTEMTIME StandardDate; SYSTEMTIME DaylightDate; } REG_TZI_FORMAT; ``` |
| *year2* | **REG_BINARY** | A **REG_TZI_FORMAT** structure. |
| *yearN* | **REG_BINARY** | A **REG_TZI_FORMAT** structure. |

For more information on other values in the **Time Zones** key, see
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information).

 Both **StandardName** and **DaylightName** are localized according to the current user default UI language.

## See also

[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-setdynamictimezoneinformation)