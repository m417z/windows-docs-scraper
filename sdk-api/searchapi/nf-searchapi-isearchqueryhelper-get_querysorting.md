# ISearchQueryHelper::get_QuerySorting

## Description

Gets the sort order for the query result set.

## Parameters

### `ppszSorting` [out, retval]

Type: **LPWSTR***

Receives a pointer to a comma-delimited, null-terminated Unicode string representing the sort order.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[Windows Search SQL](https://learn.microsoft.com/windows/desktop/search/-search-sql-ovwofsearchquery) supports sorting on multiple properties, in either ascending (ASC) or descending (DESC) order on each property. For example, the value pointed to by *ppszSorting* might contain the following:

`System.ItemAuthors ASC, System.ItemDate DESC`

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QuerySorting](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querysorting)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)