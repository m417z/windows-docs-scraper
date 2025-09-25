# CHStringArray::ElementAt

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ElementAt** method returns a temporary reference to the element pointer within the array.

## Parameters

### `nIndex`

An integer index that is greater than or equal to zero and less than or equal to the value returned by [GetUpperBound](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getupperbound).

## Return value

If the **ElementAt** method is successful, it returns a reference to the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string at the *nIndex* position in the [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) array.

## Remarks

Use the **ElementAt** method to implement the left-side assignment operator for arrays. This is an advanced method, which you should use only to implement special array operators.

#### Examples

See the example for [CHStringArray::GetSize](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getsize).

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::GetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getat(int))

[CHStringArray::GetData](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-getdata)

[CHStringArray::SetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setat(int_lpcwstr))