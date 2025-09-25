# ISearchScopeRule::get_IsDefault

## Description

Gets a value that identifies whether this is a default rule.

## Parameters

### `pfIsDefault` [out, retval]

Type: **BOOL***

On return, points to the **TRUE** for default rules and **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.