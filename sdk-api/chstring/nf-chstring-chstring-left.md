# CHString::Left

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Left** method extracts the first (that is, leftmost) *nCount* characters from a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string and returns a copy of the extracted substring. If *nCount* exceeds the string length, then the entire string is extracted.

## Parameters

### `nCount`

The number of characters extracted from the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string.

## Return value

Returns a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string containing a copy of the specified range of characters.

**Note** The returned [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string may be empty.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Mid](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-mid(int_int))

[CHString::Right](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-right)