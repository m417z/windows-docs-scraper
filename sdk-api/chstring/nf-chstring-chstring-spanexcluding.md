# CHString::SpanExcluding

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SpanExcluding** method extracts and returns all characters preceding the first occurrence of a character from *lpszCharSet*.

## Parameters

### `lpszCharSet`

A string interpreted as a set of characters.

## Return value

The **SpanExcluding** method returns a substring that begins with the first character in the string and ends with the first character found in the string that is also in *lpszCharSet*.

If no character in *lpszCharSet* is found in the string, the method returns the entire string.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::SpanIncluding](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-spanincluding)