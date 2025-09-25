# CHString::CompareNoCase

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **CompareNoCase** method uses the _wcsicmp function to compare a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string with another string.

## Parameters

### `lpsz`

The other string used for comparison.

## Return value

The **CompareNoCase** method returns the following values.

## Remarks

The **CompareNoCase** method, which performs a case-insensitive comparison of the strings, is not affected by locale.

#### Examples

The following code example shows the use of **CHstring::CompareNoCase**:

```cpp
CHString s1( L"abc" );
CHString s2( L"ABD" );

// Compare with a CHString.
assert( s1.CompareNoCase( s2 ) == 0 );
// Compare with LPCWSTR string.
assert( s1.CompareNoCase( L"ABE" ) < 0 );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Collate](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-collate)

[CHString::Compare](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-compare)