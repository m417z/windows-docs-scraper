# WBEMTime::operator-less-than

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) comparison operators (== != < <= > >=) have been overloaded to compare two **WBEMTime** objects.

## Parameters

### `a` [ref]

Reference to the [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object whose time is compared to this one.

## Return value

True if this time is less than the time specified by *uTarget*.