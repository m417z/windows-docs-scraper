# CHStringArray::Append

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Append** method adds the contents of another array to the end of the given array.

## Parameters

### `src` [ref]

Source of the elements to be appended to the array.

## Return value

If the **Append** method is successful, it returns the index of the first appended element.

## Remarks

If necessary, **Append** can allocate extra memory to accommodate the elements appended to the array.

#### Examples

The following code example shows the use of **CHStringArray::Append**.

```cpp
CHStringArray myArray1, myArray2;
int idx, size;

// Add elements to the second array.
myArray2.Add( L"String 2" );
myArray2.Add( L"String 3" );

// Add elements to the first array and also append the second array.
myArray1.Add( L"String 1" );
myArray1.Append( myArray2 );

size = myArray1.GetSize();
for (idx=0; idx<size; idx++)
   printf("[%d]: %S\n", idx, myArray1[idx]);
```

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::Add](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-add)

[CHStringArray::Copy](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-copy)