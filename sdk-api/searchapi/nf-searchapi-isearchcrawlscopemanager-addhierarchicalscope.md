# ISearchCrawlScopeManager::AddHierarchicalScope

## Description

Adds a hierarchical scope to the search engine.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

The URL of the scope to be added.

### `fInclude` [in]

Type: **BOOL**

**TRUE** if this is an inclusion scope, **FALSE** if this is an exclusion scope.

### `fDefault` [in]

Type: **BOOL**

**TRUE** if this is to be the default scope, **FALSE** if this is not a default scope.

### `fOverrideChildren` [in]

Type: **BOOL**

**TRUE** if this scope overrides all of the child URL rules, **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method overrides existing scope rules for the URL.The preferred methods for such functionality are [ISearchCrawlScopeManager::AddDefaultScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-adddefaultscoperule) and [ISearchCrawlScopeManager::AddUserScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-adduserscoperule).

URLs passed in as parameters to **ISearchCrawlScopeManager::AddHierarchicalScope** are expected to be fully URL-decoded and without URL control codes. For example, file:///c:\My Documents is fully URL-decoded, whereas file:///c:\My%20Documents is not.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.