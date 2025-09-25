# CHString::GetAt(int)

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetAt** method returns a single character specified by an index number.

## Parameters

### `nIndex`

Zero-based index of the character in the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string.

**Note** The *nIndex* parameter must be greater than or equal to zero (0), and less than the value returned by [GetLength](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getlength). The debug version of the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) library validates the bounds of *nIndex*; the release version does not.

## Return value

Returns a **WCHAR** that contains the character at the specified place in the string.

## Remarks

The overloaded subscript ([[]](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa386162(v=vs.85))) operator is a convenient alternative for **GetAt**.

#### Examples

The following code example shows the use of **CHString::GetAt**:

```cpp
CHString s( L"abcdef" );
assert( s.GetAt(2) == 'c' );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetLength](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getlength)

[CHString::operator[]](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa386162(v=vs.85))