# CHStringArray::GetUpperBound

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetUpperBound** method gets the current upper bound of an array. Because array indexes are zero-based, this function returns a value that is one less than [GetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getsize).

## Return value

If the **GetUpperBound** method is successful, it returns the upper bounds of this array. A value of -1 indicates that the array contains no elements.

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::GetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getsize)

[CHStringArray::SetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setsize)