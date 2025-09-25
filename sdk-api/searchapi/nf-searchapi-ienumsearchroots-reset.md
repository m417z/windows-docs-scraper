# IEnumSearchRoots::Reset

## Description

Moves the internal counter to the beginning of the list so a subsequent call to [IEnumSearchRoots::Next](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-ienumsearchroots-next) retrieves from the beginning.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.