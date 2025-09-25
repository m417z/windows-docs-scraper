# ISearchCatalogManager::NumberOfItemsToIndex

## Description

Gets the number of items to be indexed within the catalog.

## Parameters

### `plIncrementalCount` [out]

Type: **LONG***

Receives a pointer to the number of items to be indexed in the next incremental index.

### `plNotificationQueue` [out]

Type: **LONG***

Receives a pointer to the number of items in the notification queue.

### `plHighPriorityQueue` [out]

Type: **LONG***

Receives a pointer to the number of items in the high-priority queue. Items in the *plHighPriorityQueue* are indexed first.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.