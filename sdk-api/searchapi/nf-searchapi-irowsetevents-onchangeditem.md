# IRowsetEvents::OnChangedItem

## Description

Called by the indexer to notify clients that an item has been modified. This item may have matched some (or all) of the criteria for the client rowset.

## Parameters

### `itemID` [in]

Type: **REFPROPVARIANT**

Specifies the item in the rowset that has changed.

### `rowsetItemState` [in]

Type: **[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)**

Specifies whether the changed item was originally in the rowset.

### `changedItemState` [in]

Type: **[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)**

Specifies whether the changed item is currently in the rowset, as a result of the change.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) for *rowsetItemState* indicates whether the item was contained in the original rowset:

* *ROWSETEVENT_ITEMSTATE_INROWSET* indicates that the item is definitely contained within your rowset.
* *ROWSETEVENT_ITEMSTATE_UNKNOWN* indicates that the item may be contained within your rowset. The containment status is not known because your rowset is not fully evaluated.
* *ROWSETEVENT_ITEMSTATE_NOTINROWSET* indicates that the item was not originally in your rowset

The [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) for *changedItemState* indicates whether the newly modified item now matches the degree to which the new item may match the original search criteria of a rowset:

* *ROWSETEVENT_ITEMSTATE_INROWSET* indicates that the item definitely belongs in your rowset.
* *ROWSETEVENT_ITEMSTATE_UNKNOWN* indicates that the item may now belong in your rowset.
* *ROWSETEVENT_ITEMSTATE_NOTINROWSET* indicates that the item does not belong in your rowset.

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