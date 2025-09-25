# WBEMTime::GetLocalOffsetForDate(const time_t &)

## Description

[The [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetLocalOffsetForDate** method returns the offset in minutes (+ or –) between GMT and local time for the FILETIME supplied in the argument.

## Parameters

### `t`

TBD

#### - tmin

Pointer to a MFC **FILETIME** structure that represents the number of 100-nanosecond intervals since January 1, 1601 as a 64-bit value.

## Return value

Returns the offset in minutes (+ or -) between GMT and local time for the time supplied in the argument.

## Remarks

These are public static functions which permit their usage anywhere without having a [WBEMTime](https://learn.microsoft.com/windows/desktop/WmiSdk/wbemtime) object.