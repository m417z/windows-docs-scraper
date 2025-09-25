# IDirectorySearch::GetPreviousRow

## Description

The **IDirectorySearch::GetPreviousRow** method gets the previous row of the search result. If the provider does not provide cursor support, it should return **E_NOTIMPL**.

## Parameters

### `hSearchResult` [in]

Provides a handle to the search context.

## Return value

This method returns the standard return values, as well as the following:

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When the **ADS_SEARCHPREF_CACHE_RESULTS** flag is not set, only forward scrolling is permitted, because the client might not cache all the query results.

#### Examples

```cpp
hr = m_pSearch->ExecuteSearch(L"(&(objectCategory=user)(st=WA))", pszAttr, dwCount, &hSearch );
if ( SUCCEEDED(hr) )
{
   while(  m_pSearch->GetNextRow(hSearch)  != S_ADS_NOMORE_ROWS )
   {
      /* Get the data */
   }
   // Print it backward
   hr = m_pSearch->GetPreviousRow( hSearch );
   while( hr != S_ADS_NOMORE_ROWS  &&  hr != E_NOTIMPL)
   {
      /* Get the data */
   }
   m_pSearch->CloseSearchHandle(hSearch);
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)