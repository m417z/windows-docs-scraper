# ISearchManager::get_UseProxy

## Description

Retrieves the proxy server to be used.

## Parameters

### `pUseProxy` [out, retval]

Type: **[PROXY_ACCESS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-proxy_access)***

Receives a pointer to the proxy server to be used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.