# WBEMTime::operator-add-assign

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class add-and-assign (+=) operator has been overloaded to increment an object's time by a time span.

## Parameters

### `ts` [ref]

Reference to the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object, whose time is added to the specified object.