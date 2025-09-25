# CHStringArray::GetData

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetData** method gains direct access to the elements in the array.

## Return value

If the **GetData** method is successful, it returns a pointer to the array of [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) pointers.

## Remarks

If no elements are available, **GetData** returns a **NULL** value.

Although direct access to the elements of an array can help you work more quickly, use caution when calling **GetData**. Any errors you make directly affect the elements of your array.

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::ElementAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-elementat(int))

[CHStringArray::FreeExtra](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-freeextra)

[CHStringArray::GetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getat(int))

[CHStringArray::SetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setat(int_lpcwstr))

[CHStringArray::SetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setsize)