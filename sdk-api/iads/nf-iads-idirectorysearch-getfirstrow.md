# IDirectorySearch::GetFirstRow

## Description

The **GetFirstRow** method gets the first row of a search result. This method will issue or reissue a new search, even if this method has been called before.

## Parameters

### `hSearchResult` [in]

Contains the search handle obtained by calling [IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch).

## Return value

This method returns the standard return values, as well as the following:

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When the **ADS_SEARCHPREF_CACHE_RESULTS** flag is not set, that is, **FALSE**, only forward scrolling is permitted, because the client might not cache all the query results. Calling **GetFirstRow** more than once from the same row requires some back-scrolling and could result in erroneous outcomes for a paged or an asynchronous search initiated through OLE DB when the results are not guaranteed to remain in the cache.

#### Examples

```cpp
hr = m_pSearch->ExecuteSearch(L"(objectCategory=contact)", pszAttr, dwCount, &hSearch);
if(SUCCEEDED(hr))
{
    while(SUCCEEDED(hr = m_pSearch->GetNextRow(hSearch)))
    {
        if(S_OK == hr)
        {
            // Get the data.
        }
        else if(S_ADS_NOMORE_ROWS == hr)
        {
            // Call ADsGetLastError to see if the search is waiting for a response.
            DWORD dwError = ERROR_SUCCESS;
            WCHAR szError[512];
            WCHAR szProvider[512];

            ADsGetLastError(&dwError, szError, 512, szProvider, 512);
            if(ERROR_MORE_DATA != dwError)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    m_pSearch->CloseSearchHandle(hSearch);
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch)