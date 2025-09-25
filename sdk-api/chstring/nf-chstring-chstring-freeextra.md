# CHString::FreeExtra

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **FreeExtra** method frees any extra memory that was previously allocated by the string but is no longer needed. This method, which reallocates the buffer to the exact length returned by [GetLength](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getlength), should reduce the memory overhead consumed by the string object.

## Return value

This method does not return a value.