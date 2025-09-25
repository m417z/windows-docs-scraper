# ISearchQueryHelper::put_QuerySorting

## Description

Sets the sort order for the query result set.

## Parameters

### `pszSorting` [in]

Type: **LPCWSTR**

A comma-delimited, null-terminated Unicode string that specifies the sort order.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*ppszSorting* must be a valid ORDER BY clause (without the ORDER BY keyword). [Windows Search SQL](https://learn.microsoft.com/windows/desktop/search/-search-sql-ovwofsearchquery) supports sorting on multiple properties, in either ascending (ASC) or descending (DESC) order on each property. For example, *ppszSorting* might contain the following:

`System.ItemAuthors ASC, System.ItemDate DESC`

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QuerySorting](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querysorting)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)