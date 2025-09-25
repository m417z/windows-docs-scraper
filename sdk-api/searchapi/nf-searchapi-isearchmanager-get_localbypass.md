# ISearchManager::get_LocalBypass

## Description

Retrieves a value that determines whether the proxy server should be bypassed to find the item or URL.

## Parameters

### `pfLocalBypass` [out, retval]

Type: **BOOL***

Receives a pointer to a **BOOL** value that indicates whether to bypass the proxy server to find an item or URL. **TRUE** to bypass the proxy (for local items); otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Proxy servers are used as a gateway between the local area network (LAN) and the Internet, primarily for security. A proxy server accepts requests for information (on other networks or the Internet) from internal systems such as servers or work stations. The proxy server then forwards the request to the Internet resource, which keeps the address of the requesting system anonymous. When the information returns from the Internet resource, the proxy server routes the information back to the requesting system. For content on the LAN, it is not necessary to go through the proxy server to access your content; this potentially saves time and extra steps.

The value retrieved by this method helps the indexer identify how to work with content that is on a local domain or network. For nonlocal content, going through the proxy server may be appropriate, if not necessary.

The setting to bypass the proxy for local domains is stored in the indexer and is set by calling the [ISearchManager::SetProxy](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchmanager-setproxy) method.

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.