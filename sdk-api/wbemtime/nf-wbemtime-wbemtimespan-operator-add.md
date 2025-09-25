# WBEMTimeSpan::operator-add

## Description

[The [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **WBEMTimeSpan** class add operator adds one time span to another, placing the sum in a new **WBEMTimeSpan** object returned by the method.

## Parameters

### `uAdd` [ref]

Reference to a [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object, whose time span is added to this one.

## Return value

The method returns a new [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object, whose time span is equal to the sum of its two **WBEMTimeSpan** arguments.