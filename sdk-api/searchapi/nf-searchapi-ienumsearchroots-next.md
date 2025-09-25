# IEnumSearchRoots::Next

## Description

Retrieves the specified number of [ISearchRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchroot) elements.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements to retrieve.

### `rgelt` [out]

Type: **[ISearchRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchroot)****

Retrieves a pointer to an array of [ISearchRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchroot) elements.

### `pceltFetched` [in, out]

Type: **ULONG***

Retrieves a pointer to the actual number of elements retrieved. Can be **NULL** if *celt* == 1; otherwise it must not be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if there were not enough items left in the enumeration to be returned, or an error value otherwise.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.