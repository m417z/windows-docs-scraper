# SEARCH_KIND_OF_CHANGE enumeration

## Description

Indicates the kind of change affecting an item when a source sink notifies a client that an item has been changed.

## Constants

### `SEARCH_CHANGE_ADD:0`

An item was added.

### `SEARCH_CHANGE_DELETE:1`

An item was deleted.

### `SEARCH_CHANGE_MODIFY:2`

An item was modified.

### `SEARCH_CHANGE_MOVE_RENAME:3`

An item was moved or renamed. Not currently supported for use with [ISearchPersistentItemsChangedSink::OnItemsChanged](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchpersistentitemschangedsink-onitemschanged).

### `SEARCH_CHANGE_SEMANTICS_DIRECTORY:0x40000`

An item is a directory. The item needs to be crawled rather than just reindexed as a document would be.

### `SEARCH_CHANGE_SEMANTICS_SHALLOW:0x80000`

Index directory properties were changed for an item.

### `SEARCH_CHANGE_SEMANTICS_UPDATE_SECURITY:0x400000`

Security on an item was changed.

## Remarks

SEARCH_CHANGE_ADD, SEARCH_CHANGE_DELETE, and SEARCH_CHANGE_MODIFY are mutually exclusive. Only one of them can be used at a time. However, any one of them can be combined with the remaining flags.

## See also

[INLINE_NOTIFY_DATA_CHANGE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965367(v=vs.85))

**Reference**

[SEARCH_ITEM_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_change)