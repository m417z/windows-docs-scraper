# WBEMTime::GetDMTFNonNtfs

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetDMTFNonNtfs** method gets a DMTF date in a
CIM [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format) from a FAT that does not have time zones.

## Return value

Returns a **BSTR** in [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Remarks

The calling function must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on the return value.

The time property of [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) is held in GMT. The **GetDMTFNonNtfs** method adjusts this time to local time, converts it to a DMTF string, and sets the UTC to "***". This is compatible with the Microsoft Windows API methods which return time without being time-zone aware.