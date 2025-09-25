# IDirectorySearch::GetNextColumnName

## Description

The **IDirectorySearch::GetNextColumnName** method gets the name of the next column in the search result that contains data.

## Parameters

### `hSearchHandle` [in]

Provides a handle to the search context.

### `ppszColumnName` [out]

Provides the address of a pointer to a method-allocated string containing the requested column name. If **NULL**, no subsequent rows contain data.

## Return value

This method returns the standard return values, as well as the following:

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This method allocates sufficient memory for the column name, but the caller must call the [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) helper function to free this memory when it is no longer needed.

#### Examples

```cpp
LPWSTR pszColumn;
m_pSearch->GetFirstRow( hSearch );
printf("Column names are: ");
while( m_pSearch->GetNextColumnName( hSearch, &pszColumn ) != S_ADS_NOMORE_COLUMNS )
{
   printf("%S ", pszColumn );
   FreeADsMem( pszColumn );
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)