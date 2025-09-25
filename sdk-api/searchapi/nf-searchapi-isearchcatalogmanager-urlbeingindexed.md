# ISearchCatalogManager::URLBeingIndexed

## Description

Gets the URL that is currently being indexed. If no indexing is currently in process, *pszUrl* is set to **NULL**.

## Parameters

### `pszUrl` [out, retval]

Type: **LPWSTR***

Receives a pointer to the URL that is currently being indexed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.