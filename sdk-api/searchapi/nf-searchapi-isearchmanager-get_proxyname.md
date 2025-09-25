# ISearchManager::get_ProxyName

## Description

Retrieves the proxy name to be used by the protocol handler.

## Parameters

### `ppszProxyName` [out, retval]

Type: **LPWSTR***

Receives a pointer to a Unicode string that contains the proxy name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.