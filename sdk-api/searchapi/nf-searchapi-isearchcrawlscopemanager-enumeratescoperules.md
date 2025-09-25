# ISearchCrawlScopeManager::EnumerateScopeRules

## Description

Returns an enumeration of all the scope rules of which this instance of the [ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager) interface is aware.

## Parameters

### `ppSearchScopeRules` [out]

Type: **[IEnumSearchScopeRules](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchscoperules)****

Returns a pointer to an [IEnumSearchScopeRules](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchscoperules) interface.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there are no rules to enumerate, or an error value otherwise.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.