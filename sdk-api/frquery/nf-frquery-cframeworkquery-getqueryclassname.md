# CFrameworkQuery::GetQueryClassName

## Description

[The [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetQueryClassName** method retrieves the class name from the query.

## Return value

Returns the class name if the operation was successful and **NULL** otherwise.

## Remarks

It is the developer's responsibility to call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on the **BSTR** returned by this method to avoid a memory leak.