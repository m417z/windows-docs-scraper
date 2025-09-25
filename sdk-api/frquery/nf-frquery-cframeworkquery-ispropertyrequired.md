# CFrameworkQuery::IsPropertyRequired

## Description

[The [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **IsPropertyRequired** method determines if a particular property was requested by the query. Both the **SELECT** and **WHERE** clauses are checked.

## Parameters

### `propName`

Name of property that is checked.

## Return value

Returns **TRUE** if the property specified by *propName* was requested and **FALSE** if it was not requested.