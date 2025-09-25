# WBEMTime::GetTime

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetTime** method returns the time as a 64-bit integer.

## Return value

Returns the time as a GMT **FILETIME** structure. If the time is invalid, it returns INVALID_TIME.

## Remarks

The method is provided to assist users in debugging.