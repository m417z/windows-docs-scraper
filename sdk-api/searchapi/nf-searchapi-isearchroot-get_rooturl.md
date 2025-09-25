# ISearchRoot::get_RootURL

## Description

Gets the URL of the starting point for this search root.

## Parameters

### `ppszURL` [out, retval]

Type: **LPWSTR***

A null-terminated, Unicode buffer that contains the URL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the memory from the returned string.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.