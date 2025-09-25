# CFrameworkQuery::GetRequiredProperties

## Description

[The [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetRequiredProperties** method returns a list of all of the properties specified in the [SELECT statement](https://learn.microsoft.com/windows/desktop/WmiSdk/select-statement-for-data-queries) of a query. It returns the properties from both the SELECT and WHERE clauses.

## Parameters

### `saProperties`

Array of properties that were included in the query's [SELECT statement](https://learn.microsoft.com/windows/desktop/WmiSdk/select-statement-for-data-queries).

## Remarks

If the returned **saProperties** array is empty, then all properties are required.