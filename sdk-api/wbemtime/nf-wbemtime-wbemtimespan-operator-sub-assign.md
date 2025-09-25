# WBEMTimeSpan::operator-sub-assign

## Description

[The [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

Compares two **WBEMTimeSpan** objects using the subtract and assign operator (–=).

## Parameters

### `uSub` [ref]

Reference to the **WBEMTimeSpan** object, whose time span is subtracted from the "this" object.

## Return value

This method returns a new [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object with a value equal to the difference in time.