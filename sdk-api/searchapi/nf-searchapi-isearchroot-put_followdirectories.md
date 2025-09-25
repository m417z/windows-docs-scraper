# ISearchRoot::put_FollowDirectories

## Description

Sets a **BOOL** value that indicates whether the search engine should follow subdirectories and hierarchical scopes for this search root.

## Parameters

### `fFollowDirectories` [in]

Type: **BOOL**

**TRUE** to follow directories or hierarchical scopes, otherwise **FALSE**. The default for this value is **TRUE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.