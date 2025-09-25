# ISearchRoot::get_HostDepth

## Description

[**get_HostDepth** may be altered or unavailable in subsequent versions of the operating system or product.]

Gets a value that indicates how far into a host tree to crawl when indexing.

## Parameters

### `pdwDepth` [out]

Type: **DWORD***

On return, points to the depth (number of levels) to crawl in the host tree.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line
options for Crawl Scope Manager (CSM) indexing operations.