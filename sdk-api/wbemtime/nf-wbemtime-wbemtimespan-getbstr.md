# WBEMTimeSpan::GetBSTR

## Description

[The [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetBSTR** method gets the time span as a **BSTR** in [Date and Time format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Return value

The time span is returned as a **BSTR** in [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Remarks

The calling method must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on the return value.