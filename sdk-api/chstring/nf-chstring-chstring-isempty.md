# CHString::IsEmpty

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **IsEmpty** method tests a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string for the empty condition.

## Return value

If the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string has a length of zero, the **IsEmpty** method returns a nonzero value. If the **CHString** string has a nonzero length, the method returns zero.