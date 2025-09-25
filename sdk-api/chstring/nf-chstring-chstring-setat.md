# CHString::SetAt

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetAt** method overwrites one character specified by an index number. If the index exceeds the bounds of the existing string, **SetAt** does not enlarge the string.

## Parameters

### `nIndex`

Zero-based index of the character in the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string.

**Note** The *nIndex* parameter must be greater than or equal to zero (0), and less than the value returned by [GetLength](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getlength). The debug version of the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) library validates the bounds of *nIndex*; the release version does not.

### `ch`

The character to insert.

## Return value

This method does not return a value.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetAt](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getat(int))