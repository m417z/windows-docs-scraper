# ISearchCatalogManager::Reset

## Description

Resets the underlying catalog by rebuilding the databases and performing a full indexing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Resetting can take a very long time, during which little or no information is available to be searched.