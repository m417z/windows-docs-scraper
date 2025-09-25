# ISearchManager::put_UserAgent

## Description

Sets the user agent string that a user agent passes to website and services to identify itself.

## Parameters

### `pszUserAgent` [in]

Type: **LPCWSTR**

The user agent string identifying the user agent.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A user agent is a client application that accesses the Internet. User agents include web browsers, search engine crawlers, download managers, and so on, and may be associated with a specific protocol such as File Transfer Protocol (FTP) or Hyper Text Transfer Protocol (HTTP).

Each user agent typically has a user agent string, such as "Mozilla/4.0", that it can pass to websites and services to identify itself.

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.