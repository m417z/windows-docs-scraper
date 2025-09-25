# ISearchCatalogManager::GetPersistentItemsChangedSink

## Description

Gets the change notification event sink interface for a client. This method is used by client applications and protocol handlers to notify the indexer of changes.

## Parameters

### `ppISearchPersistentItemsChangedSink` [out, retval]

Type: **[ISearchPersistentItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchpersistentitemschangedsink)****

Receives the address of a pointer to a new [ISearchPersistentItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchpersistentitemschangedsink) interface for this catalog.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.