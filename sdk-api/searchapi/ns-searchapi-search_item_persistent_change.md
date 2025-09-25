# SEARCH_ITEM_PERSISTENT_CHANGE structure

## Description

Contains information about the kind of change that has occurred in an item to be indexed. This structure is used with the [ISearchPersistentItemsChangedSink::OnItemsChanged](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchpersistentitemschangedsink-onitemschanged) method to pass information to the indexer about what has changed.

## Members

### `Change`

Type: **[SEARCH_KIND_OF_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_kind_of_change)**

A value from the [SEARCH_KIND_OF_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_kind_of_change) enumerated type that indicates the kind of change.

### `URL`

Type: **LPWSTR**

Pointer to a null-terminated Unicode string containing the URL of the item in a SEARCH_CHANGE_ADD, SEARCH_CHANGE_MODIFY, or SEARCH_CHANGE_DELETE notification. In the case of a move, this member contains the new URL of the item.

### `OldURL`

### `Priority`

Type: **[SEARCH_NOTIFICATION_PRIORITY](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_notification_priority)**

A value from the [SEARCH_NOTIFICATION_PRIORITY](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_notification_priority) enumerated type that indicates the priority of the change.

## Remarks

SEARCH_CHANGE_MOVE_RENAME is not supported for use with [ISearchPersistentItemsChangedSink::OnItemsChanged](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchpersistentitemschangedsink-onitemschanged).