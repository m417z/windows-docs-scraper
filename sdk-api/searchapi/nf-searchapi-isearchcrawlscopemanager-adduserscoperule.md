# ISearchCrawlScopeManager::AddUserScopeRule

## Description

Adds a new crawl scope rule when the user creates a new rule or adds a URL to be indexed.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

The URL to be indexed.

### `fInclude` [in]

Type: **BOOL**

**TRUE** if this should be included in all *pszUrl* searches; otherwise, **FALSE**.

### `fOverrideChildren` [in]

Type: **BOOL**

A **BOOL** value specifying whether child rules should be overridden. If set to **TRUE**, this essentially removes all child rules.

### `fFollowFlags` [in]

Type: **DWORD**

Sets the [FOLLOW_FLAGS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-follow_flags) to specify whether to follow complex URLs and whether a URL is to be indexed or just followed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A scope rule can be a fully qualified URL or a rule with a pattern.

**ISearchCrawlScopeManager::AddUserScopeRule** overrides any existing scope rule for the URL or pattern.

URLs passed in as parameters to **ISearchCrawlScopeManager::AddUserScopeRule** are expected to be fully URL-decoded and without URL control codes. For example, file:///c:\My Documents is fully URL-decoded, whereas file:///c:\My%20Documents is not.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.