# ISearchManager::get_UserAgent

## Description

Retrieves the user agent string.

## Parameters

### `ppszUserAgent` [out, retval]

Type: **LPWSTR***

Receives the address of a pointer to the user agent string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.