# ISearchPersistentItemsChangedSink::OnItemsChanged

## Description

Notifies the indexer to index changed items.

## Parameters

### `dwNumberOfChanges` [in]

Type: **DWORD**

The number of changes being reported.

### `DataChangeEntries` [in]

Type: **[SEARCH_ITEM_PERSISTENT_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_persistent_change)[]**

An array of structures of type [SEARCH_ITEM_PERSISTENT_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_persistent_change) identifying the details for each change.

### `hrCompletionCodes` [out]

Type: **HRESULT[]**

Indicates whether each URL was accepted for indexing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.