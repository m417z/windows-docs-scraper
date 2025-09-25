# ISearchCrawlScopeManager::AddDefaultScopeRule

## Description

Adds a URL as the default scope for this rule.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated, Unicode buffer that contains the URL to use as a default scope.

### `fInclude` [in]

Type: **BOOL**

**TRUE** if *pszUrl* should be included in indexing; **FALSE** if it should be excluded.

### `fFollowFlags` [in]

Type: **DWORD**

Sets the [FOLLOW_FLAGS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-follow_flags) to specify whether to follow complex URLs and whether a URL is to be indexed or just followed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Default scope rules provide an initial set of scope rules. User scope rules always take precedence over default scope rules, unless user-defined rules are reverted in which case the default scope rules are reinstated.

URLs passed in as parameters to **ISearchCrawlScopeManager::AddDefaultScopeRule** are expected to be fully URL-decoded and without URL control codes. For example, file:///c:\My Documents is fully URL-decoded, whereas file:///c:\My%20Documents is not.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.