# ISearchCatalogManager::ReindexSearchRoot

## Description

Re-indexes all URLs from a specified root.

## Parameters

### `pszRootURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated, Unicode buffer that contains the URL on which the search is rooted. This URL must be a search root previously registered with [ISearchCrawlScopeManager::AddRoot](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-addroot).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The indexer begins an incremental crawl of all start pages under *pszRootURL* upon successful return of method.

Old information remains in the catalog until replaced by new information during the re-indexing.