# ISearchRoot::get_FollowDirectories

## Description

Gets a **BOOL** value that indicates whether the search engine follows subdirectories and hierarchical scopes.

## Parameters

### `pfFollowDirectories` [out, retval]

Type: **BOOL***

On return, points to **TRUE** if the search engine follows subdirectories and hierarchical scopes; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.