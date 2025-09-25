# ISearchQueryHelper::get_QuerySyntax

## Description

Gets the syntax of the query.

## Parameters

### `pQuerySyntax` [out, retval]

Type: **[SEARCH_QUERY_SYNTAX](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_query_syntax)***

Receives a pointer to a value from the [SEARCH_QUERY_SYNTAX](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_query_syntax) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The allowed syntaxes are Simple, Natural Query Syntax (NQS), and Advanced Query Syntax (AQS). If not set, the default query syntax is SEARCH_ADVANCED_QUERY_SYNTAX.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QuerySyntax](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querysyntax)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)