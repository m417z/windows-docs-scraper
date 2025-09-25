# ISearchRoot::put_UseNotificationsOnly

## Description

Sets a value that indicates whether this search root should be indexed only by notification and not crawled.

## Parameters

### `fUseNotificationsOnly` [in]

Type: **BOOL**

**TRUE** if this search root should be indexed only by notification; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For search root URLs in a custom data store or on a remote system, it can be useful to limit the search engine to indexing the URLs only if the store or system has sent notifications that something has changed. This might help to reduce traffic in the store or across the network by avoiding the incremental crawls when the store is unchanged.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.