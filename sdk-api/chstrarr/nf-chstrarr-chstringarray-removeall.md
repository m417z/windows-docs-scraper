# CHStringArray::RemoveAll

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **RemoveAll** method removes all the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) members from this array.

## Remarks

The **RemoveAll** method works on empty arrays.

#### Examples

The following code example shows the use of **CHStringArray::RemoveAll**.

```cpp
CHStringArray array;

array.Add( L"String 1" ); // Element 0
array.Add( L"String 2" ); // Element 1
assert( array.GetSize() == 2 );
array.RemoveAll();
assert( array.GetSize() == 0 );
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::FreeExtra](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-freeextra)