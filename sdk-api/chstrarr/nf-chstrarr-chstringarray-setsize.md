# CHStringArray::SetSize

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetSize** method establishes the size of an empty or existing array.

## Parameters

### `nNewSize`

The new array size (number of elements). The value must be greater than or equal to 0 (zero).

### `nGrowBy`

The minimum number of element slots to allocate if a size increase is necessary.

## Return value

This method does not return a value.

## Remarks

The **SetSize** method allocates memory if necessary. If the new size is smaller than the old size, then the array is truncated, and all unused memory is released. For efficiency, call **SetSize** to set the size of the array before using it. This prevents the need to reallocate and copy the array each time an item is added.

The *nGrowBy* parameter affects internal memory allocation while the array is growing. Its use never affects the array size as reported by [GetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getsize) and [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound).

#### Examples

See the example for [CHStringArray::GetData](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getdata).

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::GetData](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getdata)

[CHStringArray::GetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getsize)

[CHStringArray::GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound)