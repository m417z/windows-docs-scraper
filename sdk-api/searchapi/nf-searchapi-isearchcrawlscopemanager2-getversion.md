# ISearchCrawlScopeManager2::GetVersion

## Description

Causes file mapping to be mapped into the address space of the calling process, and informs clients if the state of the Crawl Scope Manager (CSM) has changed.

## Parameters

### `plVersion` [out]

Type: **LONG****

Receives a pointer to the address of a memory mapped file that contains the crawl scope version.

### `phFileMapping` [out]

Type: **HANDLE***

Receives a pointer to the handle of the file mapping object, with read-only access, that was used to create the memory mapped file that contains the crawl scope version.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The version number that is retrieved is always current, and changes as the state of the CSM, such as whether additions or removals were made to the crawl scope, for example. Hence, **ISearchCrawlScopeManager2::GetVersion** needs to be called only once, because the current version always remains available through the retrieved pointer.

**ISearchCrawlScopeManager2::GetVersion** does not result in a cross-process call. If the method succeeds, then the client must perform the following actions to destroy all file views in its address space, and then close the file mapping object's handle and the file on disk:

* Call **UnmapViewOfFile** using the pointer of the memory-mapped file provided by *plVersion*
* Call **CloseHandle** using the handle of the file mapping object

The client must perform these steps when finished using the memory mapped file, to prevent memory leaks.

**Windows 7 and later**: Check out the [CrawlScopeCommandLine code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-crawlscopecommandline) to see how to define command line options for Crawl Scope Manager (CSM) indexing operations.