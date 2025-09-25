# ISearchCrawlScopeManager::EnumerateRoots

## Description

Returns an enumeration of all the roots of which this instance of the [ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager) is aware.

## Parameters

### `ppSearchRoots` [out, retval]

Type: **[IEnumSearchRoots](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchroots)****

Returns a pointer to an [IEnumSearchRoots](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchroots) interface.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there are no roots to enumerate, or an error value otherwise.

## Remarks

*ppSearchRoots* is set to **NULL** if there are no roots to enumerate.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.