# ROWSETEVENT_ITEMSTATE enumeration

## Description

Describes whether an item that matches the search criteria of a rowset is currently in that rowset.

## Constants

### `ROWSETEVENT_ITEMSTATE_NOTINROWSET:0`

The item is definitely not in the rowset.

### `ROWSETEVENT_ITEMSTATE_INROWSET:1`

The item is definitely contained within the rowset.

### `ROWSETEVENT_ITEMSTATE_UNKNOWN:2`

The item may be in the rowset.

## Remarks

This enumeration is used by [IRowsetEvents](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetevents) to describe the state of rows in a rowset held by a client.

Check out the [SearchEvents code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-searchevents).

## See also

**Conceptual**

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[Notifications Process (Windows Search)](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-support)

[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)

[PRIORITY_LEVEL](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-priority_level)

[ROWSETEVENT_TYPE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_type)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)