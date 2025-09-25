# ISearchManager::get_BypassList

## Description

Gets a proxy bypass list from the indexer. This list is used to determine which items or URLs are local and do not need to go through the proxy server. This list is set by calling [ISearchManager::SetProxy](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchmanager-setproxy).

## Parameters

### `ppszBypassList` [out, retval]

Type: **LPWSTR***

Receives a pointer to the proxy bypass list that is stored in the indexer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.