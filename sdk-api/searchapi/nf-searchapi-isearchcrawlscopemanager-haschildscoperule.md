# ISearchCrawlScopeManager::HasChildScopeRule

## Description

Identifies whether a given URL has a child rule in scope.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

A string containing the URL to check for a child rule. The string can contain wildcard characters, such as asterisks (*).

### `pfHasChildRule` [out, retval]

Type: **BOOL***

**TRUE** if *pszURL* has a child rule; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.