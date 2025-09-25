# CHStringArray::GetAt(int)

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetAt** method gets the array element at the specified index.

## Parameters

### `nIndex`

An integer index that is greater than or equal to zero (0), and less than or equal to the value returned by [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound).

**Note** The *nIndex* parameter must be greater than or equal to 0. The debug version of the [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) library validates the bounds of *nIndex*; the release version does not.

## Return value

If the **GetAt** method is successful, it returns the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) pointer element currently at this index.

## Remarks

Passing a negative value or a value greater than the value returned by [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound) results in a failed assertion for debug builds.

#### Examples

The following code example shows the use of **CHStringArray::GetAt**.

```cpp
CHStringArray array;

array.Add( L"String 1" ); // Element 0
array.Add( L"String 2" ); // Element 1
assert( array.GetAt( 0 ) == "String 1" );
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::ElementAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-elementat(int))

[CHStringArray::GetData](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getdata)

[CHStringArray::SetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setat(int_lpcwstr))

[CHStringArray::operator []](https://learn.microsoft.com/windows/desktop/WmiSdk/chstringarray--operator-brackets)