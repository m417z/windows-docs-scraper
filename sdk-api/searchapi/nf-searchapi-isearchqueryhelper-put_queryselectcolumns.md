# ISearchQueryHelper::put_QuerySelectColumns

## Description

Sets the columns (or properties) requested in the select statement.

## Parameters

### `pszSelectColumns` [in]

Type: **LPCWSTR**

Pointer to a comma-delimited, null-terminated Unicode string that specifies one or more columns in the property store. Separate multiple column specifiers with commas: "System.Document.Author,System.Document.Title".

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

No defined and fixed set of properties applies to all documents. For this reason, the SQL asterisk is not permitted in the <columns> setting. For a list of valis Shell system properties, refer to [System Properties](https://msdn.microsoft.com/library/bb763010(VS.85).aspx).

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QuerySelectColumns](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_queryselectcolumns)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)

[System Properties](https://msdn.microsoft.com/library/ff518152(v=VS.85).aspx)