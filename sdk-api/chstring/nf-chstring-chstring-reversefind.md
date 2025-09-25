# CHString::ReverseFind

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ReverseFind** method searches a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string for the last match of a substring. This method is similar to the runtime function, wcsrchr.

## Parameters

### `ch`

The character that the method searches for.

## Return value

Returns the zero-based index of the last character in the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string that matches the requested character. If the character is not found, the method returns a value of -1.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Find](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-find(wchar))

[CHString::FindOneOf](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-findoneof)