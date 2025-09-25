# ISearchQueryHelper::GenerateSQLFromUserQuery

## Description

Generates a Structured Query Language (SQL) query based on a client-supplied query string expressed in either Advanced Query Syntax (AQS) or Natural Query Syntax (NQS).

## Parameters

### `pszQuery` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string containing a query in AQS or NQS.

### `ppszSQL` [out, retval]

Type: **LPWSTR***

Receives the address of a pointer to a SQL query string based on the query in the *pszQuery* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method generates SQL in the following form:

``` syntax
SELECT <QuerySelectColumns> FROM <CatalogName that created query helper>
    WHERE <Result of interpreting the User query passed into this function according to QuerySyntax>
          [ AND|OR <QueryWhereRestrictions>]
```

The SQL generation uses the settings specified in [ISearchQueryHelper::put_QueryTermExpansion](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querytermexpansion), [ISearchQueryHelper::put_QueryContentProperties](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querycontentproperties), and [ISearchQueryHelper::put_QueryContentLocale](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-put_querycontentlocale).

**ISearchQueryHelper::GenerateSQLFromUserQuery** uses regional locale settings. However, [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) does not use the regional locale settings. As a result, there are inconsistencies in the SQL returned from **ISearchQueryHelper::GenerateSQLFromUserQuery** and **ISearchQueryHelper** for region specific settings such as date formats. For example, if you set the locale for date/time to something other than the system locale, such as en-CA if the system locale is en-US, and enter `Toybox -m -i "date:3/7/2008" -Y -s`, the SQL returned will differ. The SQL from **ISearchQueryHelper::GenerateSQLFromUserQuery** will have parsed 3/7/2008 according to en-CA (seeking items dated 3rd of July, 2008) while the SQL from **ISearchQueryHelper** will have parsed 3/7/2008 according to en-US (seeking items dated 7th of March, 2008).

Checkout the [DSearch code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-dsearch) to see how to create a class for a static console application to query Windows Search using the Microsoft.Search.Interop assembly for [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper).

## See also

[ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper)

[ISearchQueryHelper::get_QuerySyntax](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchqueryhelper-get_querysyntax)

[Querying the Index Programmatically](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-qryidx-overview)

[Querying the Index with Windows Search SQL Syntax](https://learn.microsoft.com/windows/desktop/search/-search-sql-windowssearch-entry)