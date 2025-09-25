# IEnumSearchRoots::Skip

## Description

Skips the specified number of elements.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements to skip.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there were not enough items left in the enumeration to skip, or an error value.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.