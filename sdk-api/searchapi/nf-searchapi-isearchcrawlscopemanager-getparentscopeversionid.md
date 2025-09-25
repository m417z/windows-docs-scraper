# ISearchCrawlScopeManager::GetParentScopeVersionId

## Description

Gets the version ID of the parent inclusion URL.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

A string containing the current URL.

### `plScopeId` [out, retval]

Type: **LONG***

On return, contains a pointer to the version ID of the parent inclusion URL for **pszUrl**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use this method to determine whether the indexer is aware of a change in a data store or scope (for example, a data store is removed and then re-added to the index), potentially requiring a new push of the hierarchical parent of the store's URL.

This ID can change if a scope rule is removed and then added again. This method returns **S_FALSE** if no parent inclusion URL was found.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.