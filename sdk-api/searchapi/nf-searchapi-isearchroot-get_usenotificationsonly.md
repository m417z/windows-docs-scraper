# ISearchRoot::get_UseNotificationsOnly

## Description

Gets a value that indicates whether this search root should be indexed only by notification and not crawled.

## Parameters

### `pfUseNotificationsOnly` [out, retval]

Type: **BOOL***

On return, points to **TRUE** if this search root should be indexed only by notification; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.