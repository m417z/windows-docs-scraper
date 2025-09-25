# ISearchQueryHelper::get_QuerySelectColumns

## Description

Gets the columns (or properties) requested in the SELECT statement of the query.

## Parameters

### `ppszSelectColumns` [out, retval]

Type: **LPWSTR***

Receives a pointer to a comma-delimited, null-terminated Unicode string that specifies the columns (or properties) to be returned from a query.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Items are represented in the property store as a row. Each row contains a number of columns that represent properties for that row or object. Not all items will have a value for a particular property. Properties must be in the property store to be subject to a select operation.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::put_QuerySelectColumns](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_queryselectcolumns)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)

[System Properties](https://msdn.microsoft.com/library/ff518152(v=VS.85).aspx)