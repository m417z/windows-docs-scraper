# CHStringArray::Add

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Add** method adds a new element to the end of an
array, increasing the array by one.

## Parameters

### `newElement`

The element to be added to the array.

## Return value

If the **Add** method is successful, it returns the
index of the added element.

## Remarks

If [SetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setsize) has been used with an nGrowBy value
greater than 1, then extra memory can be allocated. However, the upper bound increases by only one.

#### Examples

The following code example shows the use of
**Add**.

```cpp
    CHStringArray array;
    CHString s( L"String 2");

    array.Add( L"String 1" ); // Element 0
    array.Add( s );           // Element 1
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Append](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-append)

[CHStringArray::Copy](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-copy)