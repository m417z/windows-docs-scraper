# CHString::Find(LPCWSTR)

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The [Find](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-find(wchar)) method searches a string for the first match of a substring.

## Parameters

### `lpszSub`

A substring that the method searches for.

## Return value

If the [Find](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-find(wchar)) method is successful, it returns the zero-based index of the first character in this [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string that matches the requested substring or characters. If the substring or character is not found, the method returns a value of -1.

## Remarks

The [Find](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-find(wchar)) method is overloaded to accept both single characters (similar to the runtime function, wcschr) and strings (similar to the runtime function, wcsstr).

#### Examples

The following code example shows the use of **CHString::Find**.

```cpp
CHString s( L"abcdef" );
assert( s.Find( 'c' ) == 2 );
assert( s.Find( L"de" ) == 3 );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::FindOneOf](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-findoneof)

[CHString::ReverseFind](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-reversefind)