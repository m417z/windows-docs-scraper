# SetDynamicTimeZoneInformation function

## Description

Sets the current time zone and dynamic daylight saving time settings. These settings control translations from Coordinated Universal Time (UTC) to local time.

## Parameters

### `lpTimeZoneInformation` [in]

A pointer to a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application must have the SE_TIME_ZONE_NAME privilege for this function to succeed. This privilege is disabled by default. Use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to enable the privilege before calling
**SetDynamicTimeZoneInformation**, and then to disable the privilege after the
**SetDynamicTimeZoneInformation** call. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[GetDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformation)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)