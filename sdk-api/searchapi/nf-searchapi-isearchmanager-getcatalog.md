# ISearchManager::GetCatalog

## Description

Retrieves a catalog by name and creates a new [ISearchCatalogManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager) object for that catalog.

## Parameters

### `pszCatalog` [in]

Type: **LPCWSTR**

The name of the catalog to be retrieved.

### `ppCatalogManager` [out, retval]

Type: **[ISearchCatalogManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager)****

Receives the address of a pointer to the [ISearchCatalogManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcatalogmanager) object that is named in *pszCatalog*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Currently Microsoft Windows Desktop Search (WDS) 3.0 supports only one catalog and it is named SystemIndex.

Check out the [ReindexMatchingUrls code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-reindexmatchingurls) to see ways to specify which files to re-index and how set it up.