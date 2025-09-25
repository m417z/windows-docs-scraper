# ISearchCrawlScopeManager::RemoveDefaultScopeRule

## Description

Removes a default scope rule from the search engine.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

A string identifying the URL or pattern of the default rule to be removed.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error otherwise.

## Remarks

URLs passed in as parameters to **ISearchCrawlScopeManager::RemoveDefaultScopeRule** are expected to be fully URL-decoded and without URL control codes. For example, file:///c:\My Documents is fully URL-decoded, whereas file:///c:\My%20Documents is not.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.