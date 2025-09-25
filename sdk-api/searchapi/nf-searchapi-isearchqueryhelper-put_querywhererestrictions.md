# ISearchQueryHelper::put_QueryWhereRestrictions

## Description

Sets the restrictions appended to a query in WHERE clauses.

## Parameters

### `pszRestrictions` [in]

Type: **LPCWSTR**

Pointer to a comma-delimited null-terminated Unicode string that specifies one or more query restrictions appended to the query in generated WHERE clause.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*pszRestrictions* must be a valid WHERE clause for Windows Search SQL (without the WHERE keyword).

When you create *pszRestrictions* with multiple restrictions, additional "WHERE" clauses concatenated to the first must start with "AND" or "OR". For example: "and contains(*, 'qqq')"

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QueryWhereRestrictions](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querywhererestrictions)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)