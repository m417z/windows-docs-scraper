# ISearchRoot::put_ProvidesNotifications

## Description

Sets a value that indicates whether the search engine is notified (by protocol handlers or other applications) about changes to the URLs under the search root.

## Parameters

### `fProvidesNotifications` [in]

Type: **BOOL**

**TRUE** if notifications are provided; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

That value that **ISearchRoot::put_ProvidesNotifications** sets is not protocol specific.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.