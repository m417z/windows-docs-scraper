# ISearchQueryHelper::get_ConnectionString

## Description

Returns the OLE DB connection string for the Window Search index.

## Parameters

### `pszConnectionString` [out, retval]

Type: **LPWSTR***

Receives a pointer to a null-terminated Unicode string that is a valid OLE DB connection string. This connection string can be used to initialize a connection to the Windows Search index and submit the SQL query returned by [ISearchQueryHelper::GenerateSQLFromUserQuery](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-generatesqlfromuserquery).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A connection string is a string version of the initialization properties needed to connect to a data store. The string can include such things as a data source, data source name, or user ID and password.

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)