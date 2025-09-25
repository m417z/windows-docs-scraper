# WBEMTime::operator-sub-assign

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class subtract-and-assign (–=) operator has been overloaded to decrement an object's time by a time span.

## Parameters

### `sub` [ref]

Reference to the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object, whose time span is subtracted from the specified object.

## Remarks

The return value is a new [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object with a value equal to the "this" object after it has been decremented.