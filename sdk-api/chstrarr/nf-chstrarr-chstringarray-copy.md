# CHStringArray::Copy

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Copy** method overwrites the elements of the given array with the elements of another array.

## Parameters

### `src` [ref]

Source of the elements to be copied to the array.

## Return value

This method does not return a value.

## Remarks

The **Copy** method does not free memory, but it allocates extra memory to accommodate the elements copied to the array.

#### Examples

The following code example shows the use of **CHStringArray::Copy**.

```cpp
CHStringArray a1, a2;
int idx, size;

a1.Add( L"String 1" );
a1.Add( L"String 2" );
a2.Add( L"String 5" );

size = a1.GetSize();
for (idx=0; idx<size; idx++)
   printf("[%d]: %S\n", idx, a1[idx]);

a1.Copy(a2);
size = a1.GetSize();
for (idx=0; idx<size; idx++)
   printf("[%d]: %S\n", idx, a1[idx]);
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::Append](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-append)