# ISearchCatalogManager::GetCrawlScopeManager

## Description

Gets an [ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager) interface for this search catalog.

## Parameters

### `ppCrawlScopeManager` [out, retval]

Type: **[ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager)****

Receives a pointer to a new [ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.