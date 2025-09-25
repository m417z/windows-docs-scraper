# ISearchCrawlScopeManager::AddRoot

## Description

Adds a new search root to the search engine.

## Parameters

### `pSearchRoot` [in]

Type: **[ISearchRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchroot)***

An [ISearchRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchroot) describing the new search root to add.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Overrides any existing root definition for the URL.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.