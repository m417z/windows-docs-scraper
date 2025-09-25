# ISearchRoot::get_EnumerationDepth

## Description

Gets the enumeration depth for this search root.

## Parameters

### `pdwDepth` [out, retval]

Type: **DWORD***

A pointer to the depth (number of levels) to enumerate.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.