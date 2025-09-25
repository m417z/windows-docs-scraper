# ISearchCrawlScopeManager::RemoveRoot

## Description

Removes a search root from the search engine.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

The URL of a search root to be removed.

## Return value

Type: **HRESULT**

Returns S_OK if successful; S_FALSE if the root is not found.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.