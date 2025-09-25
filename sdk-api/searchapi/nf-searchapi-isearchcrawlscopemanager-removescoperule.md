# ISearchCrawlScopeManager::RemoveScopeRule

## Description

Removes a scope rule from the search engine.

## Parameters

### `pszRule` [in]

Type: **LPCWSTR**

The URL or pattern of a scope rule to be removed.

## Return value

Type: **HRESULT**

Returns S_OK if successful; returns S_FALSE if the scope rule is not found.

## Remarks

URLs passed in as parameters to **ISearchCrawlScopeManager::RemoveScopeRule** are expected to be fully URL-decoded and without URL control codes. For example, file:///c:\My Documents is fully URL-decoded, whereas file:///c:\My%20Documents is not.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.