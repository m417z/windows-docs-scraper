# CHStringArray::RemoveAt

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **RemoveAt** method removes one or more elements starting at a specified index in an array.

## Parameters

### `nIndex`

An integer index that is greater than or equal to zero and less than or equal to the value returned by [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound).

### `nCount`

The number of elements to remove. The default is 1 (one).

## Remarks

In the process of removing elements, **RemoveAt** shifts down all the elements located above the elements that are removed. This method decrements the upper bound of the array but does not free memory.

#### Examples

The following code example shows the use of **CHStringArray::RemoveAt**.

```cpp
CHStringArray array;

array.Add( L"String 1" ); // Element 0
array.Add( L"String 2" ); // Element 1
array.RemoveAt( 0 );  // Element 1 moves to 0.
assert ( array[0] == L"String 2" );
```

The results from this program are as follows.

```cpp
[0] = String 2
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::GetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getat(int))

[CHStringArray::InsertAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-insertat(int_chstringarray))