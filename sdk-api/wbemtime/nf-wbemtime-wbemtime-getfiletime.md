# WBEMTime::GetFILETIME

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetFILETIME** method gets the time as an MFC **FILETIME** structure.

## Parameters

### `pst`

MFC **FILETIME** structure. The **FILETIME** structure is a 64-bit value that represents the number of 100-nanosecond intervals since January 1, 1601.

## Return value

The method returns **TRUE** if the time is valid and **FALSE** if the time is not valid. If **FALSE** is returned, the value of *pst* is indeterminate.