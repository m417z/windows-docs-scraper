# IEnumSearchScopeRules::Next

## Description

Retrieves the specified number of [ISearchScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchscoperule) elements.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements to retrieve.

### `pprgelt` [out]

Type: **[ISearchScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchscoperule)****

A pointer to an array which this method will initialize with [ISearchScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchscoperule) elements.

### `pceltFetched` [in, out]

Type: **ULONG***

A pointer that this method will set to the actual number of elements retrieved. Can be **NULL** if *celt* == 1, otherwise it must not be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there were not enough items left in the enumeration to be returned, or an error value.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.