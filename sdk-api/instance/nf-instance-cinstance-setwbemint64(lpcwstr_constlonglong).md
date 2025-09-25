## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetWBEMINT64(LPCWSTR, const LONGLONG&)** method sets a 64-bit integer value.

## Parameters

### `name`

Name of the 64-bit integer property that is set.

### `i64Value` [ref]

Value assigned to the 64-bit integer property.

## Return value

Returns **TRUE** if the operation is successful and **FALSE** if an attempt was made to set a nonexistent property or a property that is not a 64-bit integer. More information is available in the log file, Framework.log.

## Remarks

The provider framework currently uses a CHString type to set the 64-bit integer rather than a WBEMINT64 type.

## See also

[CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance)

[CInstance::GetWBEMINT64](https://learn.microsoft.com/windows/desktop/WmiSdk/cinstance-getwbemint64)