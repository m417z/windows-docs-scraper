# ISearchItemsChangedSink::OnItemsChanged

## Description

Call this method to notify an indexer to re-index some changed items.

## Parameters

### `dwNumberOfChanges` [in]

Type: **DWORD**

The number of items that have changed.

### `rgDataChangeEntries` [in]

Type: **[SEARCH_ITEM_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_change)[]**

An array of [SEARCH_ITEM_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_change) structures, describing the type of changes to and the paths or URLs of each item.

### `rgdwDocIds` [out]

Type: **DWORD[]**

Receives a pointer to an array of document identifiers for the items that changed.

### `rghrCompletionCodes` [out]

Type: **HRESULT[]**

Receives a pointer to an array of completion codes for *rgdwDocIds* indicating whether each item was accepted for indexing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When there are multiple change notifications, the **priority** member of the [SEARCH_ITEM_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_change) structure indicates the priority of processing.

## See also

[ISearchItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchitemschangedsink)

[Notifying the Index of Changes](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-notifyingofchanges)