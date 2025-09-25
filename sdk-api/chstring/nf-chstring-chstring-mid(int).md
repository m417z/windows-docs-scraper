# CHString::Mid(int)

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [Mid](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-mid(int_int)) method extracts a substring of length *nCount* characters from a
**CHString** string, starting at position *nFirst* (zero-based). The method returns a copy of the extracted substring.

## Parameters

### `nFirst`

The zero-based index of the first character in this **CHString** string that is be included in the extracted substring.

## Return value

Returns a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object that contains a copy of the specified range of characters. The returned **CHString** object may be empty.

## Remarks

The [Mid](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-mid(int_int)) method is similar to the Basic **MID$** function except in the Basic **MID$** function, indexes are zero-based.

#### Examples

The following code example shows the use of **CHString::Mid**.

```cpp
CHString s( L"abcdef" );
assert( s.Mid( 2, 3 ) == L"cde" );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Left](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-left)

[CHString::Right](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-right)