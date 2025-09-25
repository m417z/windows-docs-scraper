# IDirectorySearch::CloseSearchHandle

## Description

The **IDirectorySearch::CloseSearchHandle** method closes the handle to a search result and frees the associated memory.

## Parameters

### `hSearchResult` [in]

Provides a handle to the search result to be closed.

## Return value

This method returns the standard return values, as well as the following:

For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The process that implements the **IDirectorySearch::CloseSearchHandle** method must also be responsible for freeing all memory allocated by the [IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch) method, including the search result and the search result handle.

The caller may call this method only once for each opened search handle and must use the [IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch) method to obtain a new search handle after issuing **IDirectorySearch::CloseSearchHandle**.

#### Examples

```cpp
ADS_SEARCH_HANDLE hSearch;
HRESULT hr;
hr = m_pSearch->ExecuteSearch(L"(&(objectCategory=user)(l=Redmond))", pszAttr, dwCount, &hSearch );
if ( SUCCEEDED(hr) )
{
   // Omit getting the data
   m_pSearch->CloseSearchHandle(hSearch);
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)

[IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch)