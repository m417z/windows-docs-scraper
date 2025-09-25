# SYNCMGR_ITEM_CAPABILITIES enumeration

## Description

Specifies the actions that can be performed against an item.

## Constants

### `SYNCMGR_ICM_NONE:0`

No capability flags are set.

### `SYNCMGR_ICM_PROVIDES_ICON:0x1`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_Icon flag.

### `SYNCMGR_ICM_EVENT_STORE:0x2`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_EventStore flag.

### `SYNCMGR_ICM_CONFLICT_STORE:0x4`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_ConflictStore flag.

### `SYNCMGR_ICM_CAN_DELETE:0x10`

The user is allowed to delete the item from the handler's folder. This can be used by an item to remove itself from the handler's sync set (for instance, remove a folder from the set of Offline Files). If this value is set, the **Delete** task is shown in the handler's folder when this item is selected.

### `SYNCMGR_ICM_CAN_BROWSE_CONTENT:0x10000`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_BrowseContent flag. If this value is set, the **Browse Content** task is added to the item's shortcut menu.

### `SYNCMGR_ICM_QUERY_BEFORE_ENABLE:0x100000`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeEnable flag.

### `SYNCMGR_ICM_QUERY_BEFORE_DISABLE:0x200000`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeDisable flag.

### `SYNCMGR_ICM_QUERY_BEFORE_DELETE:0x400000`

The item returns a valid object from [ISyncMgrSyncItem::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeDelete flag.

### `SYNCMGR_ICM_VALID_MASK:0x710017`

A mask used to retrieve valid [SYNCMGR_ITEM_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) flags.

## Remarks

Sync Center queries the item for its capabilities through [ISyncMgrSyncItem::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities) whenever the [ISyncMgrControl::UpdateItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updateitem) method is called.