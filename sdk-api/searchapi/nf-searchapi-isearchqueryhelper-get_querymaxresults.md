# ISearchQueryHelper::get_QueryMaxResults

## Description

Gets the maximum number of results to be returned by the query.

## Parameters

### `pcMaxResults` [out, retval]

Type: **LONG***

Receives a pointer to the maximum number of results to be returned by the query. Negative numbers return all results.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QueryMaxResults](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querymaxresults)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)