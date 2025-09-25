# IDirectorySearch::AbandonSearch

## Description

The **IDirectorySearch::AbandonSearch** method abandons a search initiated by an earlier call to the [ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch) method.

## Parameters

### `phSearchResult` [in]

Provides a handle to the search context.

## Return value

This method returns the standard return values, including S_OK if the first row is obtained successfully.

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

**IDirectorySearch::AbandonSearch** may be used if the Page_Size or Asynchronous options can be specified through [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) before the search is executed.

#### Examples

```cpp
LPWSTR pszAttr[] = { L"ADsPath", L"Name", L"samAccountName" };
ADS_SEARCH_HANDLE hSearch;
DWORD dwCount= sizeof(pszAttr)/sizeof(LPWSTR);
////////////////////////////////////////////////////////////////////
// NOTE: Assume that m_pSearch is an IDirectorySearch pointer to the
// object at the base of the search, and that the appropriate search
// preferences have been set.
// For brevity, omit error handling.
////////////////////////////////////////////////////////////////////

// Search for all users with a last name that starts with h.
hr = m_pSearch->ExecuteSearch(L"(&(objectClass=user)(sn=h*))", pszAttr, dwCount, &hSearch );
while( m_pSearch->GetNextRow( hSearch) != S_ADS_NOMORE_ROWS )
{
    // Get the samAccountName
    hr = m_pSearch->GetColumn( hSearch, pszAttr[2], &col );
    if ( FAILED(hr) )
    {
        hr = m_pSearch->AbandonSearch( hSearch );
        hr = m_pSearch->CloseSearchHandle(hSearch);
        m_pSearch->Release();
        break;
    }
    if (col.dwADsType == ADSTYPE_CASE_IGNORE_STRING)
       printf("%S\n", col.pADsValues->CaseIgnoreString);
   m_pSearch->FreeColumn( &col );
}

m_pSearch->CloseSearchHandle( hSearch );
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch)

[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference)