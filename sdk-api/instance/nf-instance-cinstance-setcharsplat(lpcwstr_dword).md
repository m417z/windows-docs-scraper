# CInstance::SetCharSplat(LPCWSTR,DWORD)

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetCharSplat(LPCWSTR, DWORD)** method sets a string.

## Parameters

### `name`

Name of the string property that is set.

### `dwResID`

Resource identifier of the new string value.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to set a nonexistent or non-string property. More information is available in the log file, Framework.log.

## See also

[CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance)

[CInstance::SetCharSplat](https://learn.microsoft.com/windows/desktop/WmiSdk/cinstance-setcharsplat)