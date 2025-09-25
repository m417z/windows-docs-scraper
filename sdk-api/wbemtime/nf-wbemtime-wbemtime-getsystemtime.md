# WBEMTime::GetSYSTEMTIME

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetSYSTEMTIME** method gets the time as an MFC **SYSTEMTIME** structure.

## Parameters

### `pst`

Pointer to a MFC **SYSTEMTIME** structure. The **SYSTEMTIME** structure represents a date and time using individual members for the month, day, year, weekday, hour, minute, second, and millisecond.

## Return value

The method returns **TRUE** if the time is valid.

The method returns **FALSE** if the time is INVALID_TIME. In this case, the value of *pst* is indeterminate.