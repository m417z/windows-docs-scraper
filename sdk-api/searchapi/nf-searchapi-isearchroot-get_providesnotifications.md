# ISearchRoot::get_ProvidesNotifications

## Description

Gets a value that indicates whether the search engine is notified (by protocol handlers or other applications) about changes to the URLs under the search root.

## Parameters

### `pfProvidesNotifications` [out, retval]

Type: **BOOL***

On return, points to **TRUE** if this search root provides notifications; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value **ISearchRoot::get_ProvidesNotifications** returns is not protocol specific.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.