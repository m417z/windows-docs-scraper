# IRowsetEvents::OnDeletedItem

## Description

Called by the indexer to notify clients that an item has been deleted. This item may have matched some (or all) of the search criteria for the client rowset.

## Parameters

### `itemID` [in]

Type: **REFPROPVARIANT**

Specifies the item in the rowset that has been deleted.

### `deletedItemState` [in]

Type: **[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)**

Specifies whether the deleted item is currently in the rowset, as a [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate) indicates whether or not the item was contained in the original rowset:

* *ROWSETEVENT_ITEMSTATE_INROWSET* indicates that the deleted item is definitely in your rowset.
* *ROWSETEVENT_ITEMSTATE_UNKNOWN* indicates that the deleted item may be in your rowset. The containment status is not known because your rowset is not fully evaluated.
* *ROWSETEVENT_ITEMSTATE_NOTINROWSET* indicates the deleted item was definitely not in your original rowset (but may have already been given via an [OnNewItem](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-irowsetevents-onnewitem) or [OnChangedItem](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-irowsetevents-onnewitem) event).

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