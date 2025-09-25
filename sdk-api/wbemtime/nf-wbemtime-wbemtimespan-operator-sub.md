# WBEMTimeSpan::operator-sub

## Description

[The [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **WBEMTimeSpan** class subtract operator (–) subtracts a time span from the object on which the method is executed. The result is a new time span that contains the difference in time.

## Parameters

### `uSub` [ref]

Reference to the [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object, whose time span is subtracted from this time span, producing a new time span.

## Return value

This method returns a new [WBEMTimeSpan](https://learn.microsoft.com/windows/desktop/api/wbemtime/nl-wbemtime-wbemtimespan) object with a value equal to the difference in time.

**Note** The new time span is set to INVALID_TIME if a negative time span results. Subtracting a time span from an object that contains INVALID_TIME produces a new time span object set to INVALID_TIME.