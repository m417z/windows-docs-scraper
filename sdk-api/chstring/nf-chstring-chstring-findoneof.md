# CHString::FindOneOf

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **FindOneOf** method searches a string for the first character that matches any character contained in *lpszCharSet*.

## Parameters

### `lpszCharSet`

String that contains characters used in the matching operation.

## Return value

If the method is successful, it returns the zero-based index of the first character in the string that is also in *lpszCharSet*. If there is no match, the method returns a value of -1.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Find](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-find(wchar))