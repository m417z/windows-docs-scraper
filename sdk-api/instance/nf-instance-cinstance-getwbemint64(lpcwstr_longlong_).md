## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class is part of the WMI Provider Framework, which is now considered in final state, and no further development, enhancements, or updates will be available for non-security related issues affecting these libraries. The [MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new development.]

The **GetWBEMINT64** method retrieves a 64-bit integer property.

## Parameters

### `name`

Name of the 64-bit integer property retrieved.

### `i64Value` [ref]

Buffer to receive the 64-bit integer value.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to set a nonexistent property or a property that is not a 64-bit integer. More information is available in the log file, `Framework.log`.

## Remarks

The provider framework currently returns a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) value rather than a **WBEMINT64** value.

## See also

[CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance)

[CInstance::GetWBEMINT64](https://learn.microsoft.com/windows/desktop/WmiSdk/cinstance-getwbemint64)