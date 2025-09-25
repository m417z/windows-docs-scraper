# ISearchManager2::CreateCatalog

## Description

Creates a new custom catalog in the Windows Search indexer and returns a reference to it.

## Parameters

### `pszCatalog` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of catalog to create. Can be any name selected by the caller, must contain only standard alphanumeric characters and underscore.

### `ppCatalogManager` [out]

Type: **[ISearchCatalogManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager)****

On success a reference to the created catalog is returned as an [ISearchCatalogManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager) interface pointer. The Release() must be called on this interface after the calling application has finished using it.

## Return value

Type: **HRESULT**

HRESULT indicating status of operation:

| Return code | Description |
| --- | --- |
| **S_OK** | Catalog did not previously exist and was created. Reference to catalog returned. |
| **S_FALSE** | Catalog previously existed, reference to catalog returned. |

FAILED HRESULT: Failure creating catalog or invalid arguments passed.

## Remarks

Called to create a new catalog in the Windows Search indexer.
After creation, the methods on the returned [ISearchCatalog](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager) manager can be used to add locations to be indexed, monitor indexing process, and construct queries to send to the indexer and get results. For more information, see [Managing the Index](https://learn.microsoft.com/windows/win32/search/-search-3x-wds-mngidx-overview).

## See also

[ISearchManager2](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchmanager2)