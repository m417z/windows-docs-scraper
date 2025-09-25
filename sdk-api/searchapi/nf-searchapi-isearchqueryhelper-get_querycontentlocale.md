# ISearchQueryHelper::get_QueryContentLocale

## Description

Gets the language code identifier (LCID) for the query.

## Parameters

### `plcid` [out, retval]

Type: **LCID***

Receives a pointer to the locale identifier used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The locale identifier has the components necessary to uniquely identify one of the installed system-defined locales. The locale retrieved is used for word breaking, normalizing, and stemming the string values extracted from the query string. If the locale identifier was not set with [ISearchQueryHelper::put_QueryContentLocale](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querycontentlocale), the active input locale is retrieved.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QueryContentLocale](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querycontentlocale)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)