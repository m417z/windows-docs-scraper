# CHStringArray::SetAtGrow

## Description

[The [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetAtGrow** method sets the array element at the specified index. The array increases automatically if necessary, adjusting the upper bound to accommodate the new element.

## Parameters

### `nIndex`

An integer index that is greater than or equal to zero (0).

**Note** The *nIndex* parameter must be greater than or equal to zero (0). The debug version of the [CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray) library validates the bounds of *nIndex*; the release version does not.

### `newElement`

The object pointer to be added to this array. A **NULL** value is allowed.

## Return value

This method does not return a value.

## See also

[CHStringArray](https://learn.microsoft.com/windows/desktop/api/chstrarr/nl-chstrarr-chstringarray)

[CHStringArray::SetAt](https://learn.microsoft.com/windows/desktop/api/chstrarr/nf-chstrarr-chstringarray-setat(int_lpcwstr))

[CHStringArray::operator []](https://learn.microsoft.com/windows/desktop/WmiSdk/chstringarray--operator-brackets)