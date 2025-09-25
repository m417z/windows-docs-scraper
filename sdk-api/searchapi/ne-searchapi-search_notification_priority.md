# SEARCH_NOTIFICATION_PRIORITY enumeration

## Description

Indicates the priority of processing an item that has changed.

## Constants

### `SEARCH_NORMAL_PRIORITY:0`

The changed item is added to the end of the indexer's queue.

### `SEARCH_HIGH_PRIORITY:1`

The changed item is placed ahead of other queued items in the indexer's queue, to be processed as soon as possible.

## Remarks

Set the **priority** member of the [SEARCH_ITEM_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-search_item_change) structure to one of these flags.

As the indexer crawls, it builds a list of items that need to be indexed. These flags indicate the placement of changed items in the indexer's queue. Higher priority items are placed at the front of the queue.