# CFrameworkQuery::GetQuery

## Description

[The [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetQuery** method retrieves the actual WQL command associated with the [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery) object.

## Return value

Returns the WQL command if the operation was successful and **NULL** otherwise.

## Remarks

If **GetQuery** is called within [Provider::GetObject](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-getobject(cinstance_long_cframeworkquery_)), the WQL command line does not contain a [WHERE](https://learn.microsoft.com/windows/desktop/WmiSdk/select-statement-for-data-queries) clause.