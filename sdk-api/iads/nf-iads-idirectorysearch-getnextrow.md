# IDirectorySearch::GetNextRow

## Description

The **GetNextRow** method gets the next row of the search result. If [IDirectorySearch::GetFirstRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getfirstrow) has not been called, **GetNextRow** will issue a new search beginning from the first row. Otherwise, this method will advance to the next row.

## Parameters

### `hSearchResult` [in]

Contains the search handle obtained by calling [IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch).

## Return value

This method returns the standard return values, as well as the following:

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When the **ADS_SEARCHPREF_CACHE_RESULTS** flag is not set, only forward scrolling is permitted, because the client might not cache all the query results.

The directory provider may limit the maximum number of rows available in a search. For example, on a Windows domain, the maximum number of rows that will be provided in an Active Directory search is 1000 rows. If the search results in more than the row limit, a paged search must be performed to obtain all rows in the search. For more information about paged searches, see [Paging with IDirectorySearch](https://learn.microsoft.com/windows/desktop/ADSI/paging-with-idirectorysearch).

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

[ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch)

[IDirectorySearch::GetFirstRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getfirstrow)