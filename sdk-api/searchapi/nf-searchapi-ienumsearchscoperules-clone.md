# IEnumSearchScopeRules::Clone

## Description

Creates a copy of this [IEnumSearchScopeRules](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchscoperules) object with the same contents and state as the current one.

## Parameters

### `ppenum` [out, retval]

Type: **[IEnumSearchScopeRules](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchscoperules)****

On return, contains a pointer to the cloned [IEnumSearchScopeRules](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-ienumsearchscoperules) object. The calling application must free the new object by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.