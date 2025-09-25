# WBEMTime::GetBSTR

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetBSTR** method gets the time as a **BSTR** value in
CIM [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Return value

The method returns a **BSTR** in [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format). The time is given as GMT. If the internal time value is INVALID_TIME, the method returns **NULL**.

## Remarks

If the value returned is not **NULL**, the calling function must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on the returned value. This method returns the same value as [WBEMTime::GetDMTF](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getdmtf)(false).

## See also

[WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime)

[WBEMTime::GetDMTF](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getdmtf)