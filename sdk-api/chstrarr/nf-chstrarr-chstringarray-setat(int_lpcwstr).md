# CHStringArray::SetAt(int,LPCWSTR)

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetAt** method sets the array element at the specified index.

## Parameters

### `nIndex`

An integer index that is greater than or equal to zero and less than or equal to the value returned by [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound).

### `newElement`

The object pointer that is inserted in this array. A **NULL** value is allowed.

## Remarks

The **SetAt** method does not cause the array to increase. Use [SetAtGrow](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setatgrow) if you want the array to increase automatically.

You must ensure that your index value represents a valid position in the array.

#### Examples

The following code example shows the use of **CHStringArray::SetAt**.

```cpp
CHStringArray array;

array.Add( L"String 1" ); // Element 0
array.Add( L"String 2" ); // Element 1
array.SetAt( 0, L"String 3" );  // Replace element 0.
assert( array[0] == "String 3" );
```

The following example results in a [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) with two elements.

```cpp
    [0] = String 3
    [1] = String 2
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::ElementAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-elementat(int))

[CHStringArray::GetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getat(int))

[CHStringArray::GetData](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getdata)

[CHStringArray::operator []](https://learn.microsoft.com/windows/desktop/WmiSdk/chstringarray--operator-brackets)