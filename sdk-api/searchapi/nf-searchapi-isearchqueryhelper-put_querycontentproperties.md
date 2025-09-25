# ISearchQueryHelper::put_QueryContentProperties

## Description

Sets the properties to include in the query if search terms do not explicitly specify properties.

## Parameters

### `pszContentProperties` [in]

Type: **LPCWSTR**

Pointer to a comma-delimited, null-terminated Unicode string of one or more properties. Separate column specifiers with commas: "Content,DocAuthor".

Set *ppszContentProperties* to **NULL** to use all properties.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Search terms may or may not be explicitly prefixed by a property ("author:Irina" or just "Irina"). If *SEARCH_ADVANCED_QUERY_SYNTAX* or *NO_QUERY_SYNTAX* is set in [ISearchQueryHelper::put_QuerySyntax](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querysyntax), all search terms not prefixed by a property keyword are matched against the list of properties in *ppszContentProperties*.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QueryContentProperties](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querycontentproperties)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)

[System Properties](https://msdn.microsoft.com/library/ff518152(v=VS.85).aspx)