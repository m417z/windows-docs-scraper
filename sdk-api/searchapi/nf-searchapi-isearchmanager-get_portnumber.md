# ISearchManager::get_PortNumber

## Description

Retrieves the port number used to communicate with the proxy server. This port number is stored in the indexer and is set by the [ISearchManager::SetProxy](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchmanager-setproxy) method.

## Parameters

### `pdwPortNumber` [out, retval]

Type: **DWORD***

Receives a pointer to the port number.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.