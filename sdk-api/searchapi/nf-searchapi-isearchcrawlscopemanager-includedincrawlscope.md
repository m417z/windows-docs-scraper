# ISearchCrawlScopeManager::IncludedInCrawlScope

## Description

Retrieves an indicator of whether the specified URL is included in the crawl scope.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

A string containing the URL to check for inclusion in the crawl scope.

### `pfIsIncluded` [out, retval]

Type: **BOOL***

A pointer to a **BOOL** value: **TRUE** if *pszURL* is included in the crawl scope; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For hierarchical sources, the most immediate parent is included. For non-hierarchical sources like URLs, this will be only the URL rule itself. Other URLs that might be indexed will cause this method to retrieve **FALSE** because there is no way to tell whether they are in the scope.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.