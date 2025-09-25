# ISearchRoot::put_RootURL

## Description

Sets the URL of the current search root.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated, Unicode buffer that contains the URL of this search root.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.