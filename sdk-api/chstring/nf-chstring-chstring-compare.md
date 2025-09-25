# CHString::Compare

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Compare** method uses the wcscmp function to compare this [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string with another string.

## Parameters

### `lpsz`

The other string used for comparison.

## Return value

The **Compare** method returns the following values.

## Remarks

The **Compare** method, which performs a case-sensitive comparison of the strings, is not affected by locale.

#### Examples

The following code example shows the use of **CHString::Compare**:

```cpp
CHString s1( L"abc" );
CHString s2( L"ABC" );

assert( s1.Compare( s2 ) > 0 ); // Compare with another CHString.
assert( s1.Compare( L"abc" ) == 0 ); // Compare with LPCWSTR string.
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Collate](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-collate)

[CHString::CompareNoCase](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-comparenocase)