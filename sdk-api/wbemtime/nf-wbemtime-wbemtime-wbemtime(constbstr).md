# WBEMTime::WBEMTime(const BSTR)

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class constructor overload method takes a **BSTR** parameter.

## Parameters

### `bstrDMTFFormat`

**BSTR** in Date and Time Format. The **BSTR** is converted to GMT.

Now when you use [WBEMTime::GetDMTF](https://learn.microsoft.com/windows/desktop/api/wbemtime/nf-wbemtime-wbemtime-getdmtf) to retrieve it you have only two choices:

* Get as Local Time
* Get as GMT

At this point, the actual offset used in the **BSTR** to build the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object has been lost.

## Remarks

If you use the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime)( **BSTR** *bstrDMTFFormat*) form of the constructor, you can only retrieve the time in one of these ways:

* Get as Local Time
* Get as GMT

The actual offset used in the **BSTR** to build the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object has been lost.

Should an "*" appear in any location in the inbound datetime string *bstrDMTFFormat*, the * is replaced on a positional basis with the default datetime string "16010101000000.000000+000".

The microsecond separator "." and UTC offset sign "+/-" must be present in the correct locations. "* "in these locations constitutes an error. All other positions are replaced by the default element if "*" is detected in the corresponding location. Invalid character symbols are not allowed.

Example: "1979**********.000000+000" appears as "197910101000000.000000+000".

"1979**********.000000+0*1" converts to "197910101000000.000000+001". Note the "*" in the UTC offset changes to 0 in the second position. On reading this datetime field the resulting UTC of 001 impacts the minute field to yield "197910100000000.000000+000".