# IDirectorySearch::GetColumn

## Description

The **IDirectorySearch::GetColumn** method gets data from a named column of the search result.

## Parameters

### `hSearchResult` [in]

Provides a handle to the search context.

### `szColumnName` [in]

Provides the name of the column for which data is requested.

### `pSearchColumn` [out]

Provides the address of a method-allocated [ADS_SEARCH_COLUMN](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_search_column) structure that contains the column from the current row of the search result.

## Return value

This method returns the standard return values, as well as the following.

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The method allocates the memory for the [ADS_SEARCH_COLUMN](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_search_column) structure to hold the data of the column. But the caller must free the memory by calling [IDirectorySearch::FreeColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-freecolumn).

The **IDirectorySearch::GetColumn** method tries to read the schema definition of the requested attribute so it can return the attribute values in the appropriate format in the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures, contained in the [ADS_SEARCH_COLUMN](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_search_column) structure. However, **GetColumn** can succeed even when the schema definition is not available, in which case the **dwADsType** member of the **ADS_SEARCH_COLUMN** structure returns ADSTYPE_PROV_SPECIFIC and the value is returned in an [ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific) structure. When you process the results of a **GetColumn** call, you must verify **dwADsType** to ensure that the data was returned in the expected format.

#### Examples

```cpp
ADS_SEARCH_COLUMN col;
/*.. Omit the set preference and execute*/
while( m_pSearch->GetNextRow( hSearch) != S_ADS_NOMORE_ROWS )
{
   // Get the Name and display it in the list.
   hr = m_pSearch->GetColumn( hSearch, pszAttr[0], &col );
   if ( SUCCEEDED(hr) )
   {
          switch (col.dwADsType)
          {
             case ADSTYPE_CASE_IGNORE_STRING:
                printf("%S\n", col.pADsValues->CaseIgnoreString);
             break;

             case ADSTYPE_PROV_SPECIFIC:
                printf("%S\n", col.pADsValues->ProviderSpecific.lpValue);
             break;

             default:
                printf("Unexpected ADsType: %d\n", col.dwADsType);
             break;
          }

          {
             m_pSearch->FreeColumn( &col );
          }
   }

}

m_pSearch->CloseSearchHandle( hSearch );

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_SEARCH_COLUMN](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_search_column)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::FreeColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-freecolumn)