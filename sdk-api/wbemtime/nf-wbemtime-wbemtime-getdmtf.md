# WBEMTime::GetDMTF

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetDMTF** method converts a **BSTR** value to
CIM [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Parameters

### `bLocal`

If **TRUE**, returns the local time, adjusted for daylight savings time; otherwise, returns GMT.

## Return value

Returns a **BSTR** in [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Remarks

The calling function must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on the return value.

## See also

[WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime)

[WBEMTime::GetBSTR](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getbstr)

[WBEMTime::SetDMTF](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-setdmtf)