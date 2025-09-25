# CHString::SpanIncluding

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SpanIncluding** method extracts characters of a string that are identified by *lpszCharSet*.

## Parameters

### `lpszCharSet`

A string interpreted as a set of characters.

## Return value

The **SpanIncluding** method returns a substring that contains characters in the string that are in *lpszCharSet*.

If the first character in the string is not in the specified set, the method returns an empty substring.

## Remarks

The **SpanIncluding** method starts with the first character of the string and stops when a character is found in the string but not in *lpszCharSet*.

#### Examples

The following code example shows the use of **CHString::SpanIncluding**.

```cpp
CHString str( L"cabbage" );
CHString res = str.SpanIncluding( L"abc" );

assert( res == L"cabba" );
res = str.SpanIncluding( L"xyz" );
assert( res.IsEmpty( ) );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::IsEmpty](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-isempty)

[CHString::SpanExcluding](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-spanexcluding)