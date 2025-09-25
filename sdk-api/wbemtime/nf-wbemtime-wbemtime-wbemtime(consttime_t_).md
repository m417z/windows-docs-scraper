# WBEMTime::WBEMTime(const time_t &)

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) overload class constructor takes an ANSI C **time_t** structure parameter.

## Parameters

### `t` [ref]

ANSI C **time_t** structure that holds the number of seconds since midnight Jan 1, 1970 (CIM format: 19700101000000.000000-000). For more information, see [Date and Time Format](https://learn.microsoft.com/windows/desktop/WmiSdk/date-and-time-format).