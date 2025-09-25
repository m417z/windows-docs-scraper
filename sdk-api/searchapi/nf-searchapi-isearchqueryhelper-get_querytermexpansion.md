# ISearchQueryHelper::get_QueryTermExpansion

## Description

Gets the value that specifies how query terms are to be expanded.

## Parameters

### `pExpandTerms` [out, retval]

Type: **[SEARCH_TERM_EXPANSION](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_term_expansion)***

Receives a pointer to a value from the [SEARCH_TERM_EXPANSION](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_term_expansion) enumeration that specifies the query term expansion.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

While the [SEARCH_TERM_EXPANSION](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_term_expansion) enumerated type lets you specify stem expansion, Windows Search does not currently support its use with the [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) interface.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QueryTermExpansion](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querytermexpansion)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)

[SEARCH_TERM_EXPANSION](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_term_expansion)