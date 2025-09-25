# WBEMTime::GetStructtm

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetStructtm** method gets the time as an ANSI C run-time **struct tm** structure.

## Parameters

### `ptm`

Pointer to an ANSI C run-time **struct tm** structure.

## Return value

The method returns **TRUE** if the object's time is equal to or later than midnight Jan 1, 1900.

The method returns **FALSE** on all other times or if the object's time is set to INVALID_TIME. In this case, the value of *ptm* is indeterminate.