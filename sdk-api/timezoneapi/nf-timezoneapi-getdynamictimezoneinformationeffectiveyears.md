# GetDynamicTimeZoneInformationEffectiveYears function

## Description

Gets a range, expressed in years, for which a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) has valid entries. Use the returned value to identify the specific years to request when calling [GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear) to retrieve time zone information for a time zone that experiences annual boundary changes due to daylight saving time adjustments.

## Parameters

### `lpTimeZoneInformation` [in]

Specifies settings for a time zone and dynamic daylight saving time.

### `FirstYear` [out]

The year that marks the beginning of the range to pass to [GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear).

### `LastYear` [out]

The year that marks the end of the range to pass to [GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear).

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation succeeded. |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the effective years. |
| **ERROR_INVALID_PARAMETER** | One of the parameter values is not valid. |
| Any other value | The operation failed. |

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[EnumDynamicTimeZoneInformation](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-enumdynamictimezoneinformation)