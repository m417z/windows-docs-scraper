# ISearchRoot::get_IsHierarchical

## Description

Gets a value that indicates whether the search is rooted on a hierarchical tree structure.

## Parameters

### `pfIsHierarchical` [out, retval]

Type: **BOOL***

On return, points to **TRUE** for hierarchical tree structures, and **FALSE** for other structures such as websites.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.