# WBEMTime::SetDMTF

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetDMTF** method sets the time in the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object. The time is given by its **BSTR** parameter in Date and Time Format. A date and time argument earlier than midnight January 1, 1601 is not valid.

## Parameters

### `wszText`

**BSTR** in [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).

## Return value

The method returns **true** if the time is valid and **false** if the time is not valid.

## Remarks

Internally, [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) stores a datetime as a 64-bit integer. Because of this, implementation-specific interpretation to the use of an asterisk is required when setting a datetime.

When an asterisk "*" appears in any location in the inbound datetime string, *wszText* is replaced on a positional basis with the default datetime string "16010101000000.000000+000".

The microsecond separator "." and UTC offset sign "+/-" must be present in the correct locations. All other positions are replaced by the default element if an asterisk is detected in the corresponding location.

For example, "1979**********.000000-0*4" becomes "197910101000000.000000-004".

Because [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) internally stores all datetime values in GMT, the resulting UTC of -004 causes the minute field to change so that the internal representation becomes "197910105000000.000000+000".

## See also

[WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime)

[WBEMTime::GetBSTR](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getbstr)

[WBEMTime::GetDMTF](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getdmtf)