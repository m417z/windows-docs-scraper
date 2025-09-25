# ISearchQueryHelper::put_QueryContentLocale

## Description

Sets the language code identifier (LCID) of the query.

## Parameters

### `lcid` [in]

Type: **LCID**

Sets the LCID of the query.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The locale identifier has the components necessary to uniquely identify one of the installed system-defined locales. The LCID controls a number of settings including numeric format, date format, currency format, uppercase and lowercase mapping, dictionary sort ordering, tokenization, and others. Although these settings help Windows operating system and Windows Search API provide excellent localized support, unexpected results can occur when documents from one locale are searched by a system set for another locale.

When the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) object processes a document's text properties and content, it reports the language of that document to the content indexer. Using this information, the Search API can apply the appropriate word breaker and noise-words list.

The locale is used for word breaking, normalizing, and stemming the string values that are extracted from the query string. If this method is not used (so the content locale is not set), [ISearchQueryHelper::get_QueryContentLocale](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querycontentlocale) returns the active input locale.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QueryContentLocale](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querycontentlocale)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)