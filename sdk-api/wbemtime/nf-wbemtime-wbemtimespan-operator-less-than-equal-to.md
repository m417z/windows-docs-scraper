# WBEMTimeSpan::operator-less-than-equal-to

## Description

[The [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

Compares two [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) objects using a less than or equal comparison operator.

## Parameters

### `a` [ref]

Reference to the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object whose time span is compared to this one.

## Return value

**TRUE** if this time span is less than or equal to the time span specified by *uTarget*.