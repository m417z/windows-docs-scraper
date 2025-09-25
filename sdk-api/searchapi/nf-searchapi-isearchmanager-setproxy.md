# ISearchManager::SetProxy

## Description

Stores information in the indexer that determines how the indexer will work and communicate with a proxy server.

## Parameters

### `sUseProxy` [in]

Type: **[PROXY_ACCESS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-proxy_access)**

Sets whether and how to use a proxy, using one of the values enumerated in [PROXY_ACCESS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-proxy_access).

### `fLocalByPassProxy` [in]

Type: **BOOL**

Sets whether the proxy server should be bypassed for local items and URLs.

### `dwPortNumber` [in]

Type: **DWORD**

Sets the port number that the index will use to talk to the proxy server.

### `pszProxyName` [in]

Type: **LPCWSTR**

A null-terminated Unicode string containing the name of the proxy server to use.

### `pszByPassList` [in]

Type: **LPCWSTR**

A null-terminated Unicode string containing a comma-delimited list of items that are considered local by the indexer and are not to be accessed through a proxy server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.