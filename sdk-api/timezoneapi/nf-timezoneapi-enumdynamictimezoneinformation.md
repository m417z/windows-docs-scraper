# EnumDynamicTimeZoneInformation function

## Description

Enumerates [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) entries stored in the registry. This information is used to support time zones that experience annual boundary changes due to daylight saving time adjustments. Use the information returned by this function when calling [GetDynamicTimeZoneInformationEffectiveYears](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformationeffectiveyears) to retrieve the specific range of years to pass to [GetTimeZoneInformationForYear](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformationforyear).

## Parameters

### `dwIndex` [in]

Index value that represents the location of a [DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information) entry.

### `lpTimeZoneInformation` [out]

Specifies settings for a time zone and dynamic daylight saving time.

## Return value

This function returns DWORD. Possible return values include:

| Value | Description |
|-------------------------|---------------------------------------------------|
| ERROR_SUCCESS | The operation succeeded. |
| ERROR_NO_MORE_ITEMS | No more data is available for the given index. |
| ERROR_INVALID_PARAMETER | A parameter is invalid. |
| Any other value | The operation failed. |

## Remarks

The following example demonstrates looping through the potential timezones until **ERROR_NO_MORE_ITEMS** is returned, indicating that there are no more time zone entries in the registry.

```cpp
std::vector<DYNAMIC_TIME_ZONE_INFORMATION> possibleTimezones;
DYNAMIC_TIME_ZONE_INFORMATION dynamicTimezone = {};
DWORD dwResult = 0;
DWORD i = 0;

do
{
    dwResult = EnumDynamicTimeZoneInformation(i++, &dynamicTimezone);
    if (dwResult == ERROR_SUCCESS)
    {
        possibleTimezones.push_back(dynamicTimezone);
    }
}
while (dwResult != ERROR_NO_MORE_ITEMS);
```

## See also

[DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-dynamic_time_zone_information)

[GetDynamicTimeZoneInformationEffectiveYears](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-getdynamictimezoneinformationeffectiveyears)