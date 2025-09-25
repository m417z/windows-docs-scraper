# IRowsetEvents::OnNewItem

## Description

Called by the indexer to notify clients of a new item that may match some (or all) of the criteria for the client rowset.

## Parameters

### `itemID` [in]

Type: **REFPROPVARIANT**

The new item that may match the original search criteria of the rowset.

### `newItemState` [in]

Type: **[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)**

Specifies whether the new item matches all or some of the criteria for your rowset, as a [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) indicates the degree to which the new item may match the original search criteria of a rowset:

* *ROWSETEVENT_ITEMSTATE_INROWSET* indicates that the new item definitely matches all criteria for your rowset.
* *ROWSETEVENT_ITEMSTATE_UNKNOWN* indicates that the new item at least partially matches some criteria for your rowset. It may match fully.
* *ROWSETEVENT_ITEMSTATE_NOTINROWSET* is not applicable for new items.

## See also

**Conceptual**

[IRowsetEvents](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetevents)

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)

[PRIORITY_LEVEL](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-priority_level)

[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)

[ROWSETEVENT_TYPE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_type)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)