# WBEMTime::operator-sub(const WBEMTimeSpan &)

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

This overload of the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class subtraction operator (–) subtracts a time span from an object's time to produce a new time object that contains the resulting time.

## Parameters

### `sub` [ref]

Reference to the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object whose time span is subtracted from the "this" object.

## Return value

When a [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object is returned, it is a new object whose time is the difference between the "this" object and the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object used as the argument.

When a [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object is returned, it is a new time span object whose value is the difference between the "this" object and the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object used as an argument.

Any returned objects that has a negative time span or a time before Jan 1, 1601 is set to INVALID_TIME.