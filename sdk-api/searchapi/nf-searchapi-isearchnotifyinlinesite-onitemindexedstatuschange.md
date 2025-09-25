# ISearchNotifyInlineSite::OnItemIndexedStatusChange

## Description

Called by the search service to notify the client when the status of a particular document or item changes.

## Parameters

### `sipStatus` [in]

Type: **[SEARCH_INDEXING_PHASE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_indexing_phase)**

The [SEARCH_INDEXING_PHASE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_indexing_phase) status of each document in the array being sent.

### `dwNumEntries` [in]

Type: **DWORD**

The number of entries in *rgItemStatusEntries*.

### `rgItemStatusEntries` [in]

Type: **[SEARCH_ITEM_INDEXING_STATUS](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_indexing_status)[]**

An array of [SEARCH_ITEM_INDEXING_STATUS](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_indexing_status) structures containing status update information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISearchNotifyInlineSite](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchnotifyinlinesite)

[Notifying the Index of Changes](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-notifyingofchanges)