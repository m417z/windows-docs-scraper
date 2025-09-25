# ISearchScopeRule::get_IsIncluded

## Description

Gets a value identifying whether this rule is an inclusion rule. Inclusion rules identify scopes that should be included in the crawl scope.

## Parameters

### `pfIsIncluded` [out, retval]

Type: **BOOL***

On return, points to **TRUE** if this rule is an inclusion rule, **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.