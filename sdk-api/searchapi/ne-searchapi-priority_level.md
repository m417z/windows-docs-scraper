# PRIORITY_LEVEL enumeration

## Description

Used by the [IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization) interface to set or retrieve the current indexer prioritization level for the scope specified by a query.

## Constants

### `PRIORITY_LEVEL_FOREGROUND:0`

Indicates that the indexer should process items as fast as the machine allows.

### `PRIORITY_LEVEL_HIGH:1`

Indicates that the indexer should process items in this scope first, and as quickly as possible.

### `PRIORITY_LEVEL_LOW:2`

Indicates that the indexer should process items in this scope before those at the normal rate, but after any other prioritization requests.

### `PRIORITY_LEVEL_DEFAULT:3`

Indicates that the indexer should process items at the normal indexer rate.

## Remarks

Check out the [SearchEvents code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-searchevents).

## See also

**Conceptual**

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)

[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)

[ROWSETEVENT_TYPE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_type)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)