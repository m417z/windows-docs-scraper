# SYNCMGR_ITEM_POLICIES enumeration

## Description

Specifies an item's policies to control how they can be enabled or disabled by group policy.

## Constants

### `SYNCMGR_IPM_NONE:0`

No policy flags are set.

### `SYNCMGR_IPM_PREVENT_ENABLE:0x1`

Enabling of the item is not supported at the time of the call. This value can be used by an item to implement support for group policy that prevents the item from being enabled. If this value is set, the **Enable** task is not shown in the handler's folder when this item is selected. The item should provide a comment—returned from its implementation of [ISyncMgrSyncItemInfo::GetComment](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynciteminfo-getcomment)—to let the user know why the **Enable** task is not available. Most items should not set this value.

### `SYNCMGR_IPM_PREVENT_DISABLE:0x2`

Disabling of the item is not supported at the time of the call. This value can be used by an item to implement support for group policy that prevents the item from being disabled. If this value is set, the **Disable** task is not shown in the handler's folder when this item is selected. The item should provide a comment—returned from its implementation of [ISyncMgrSyncItemInfo::GetComment](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynciteminfo-getcomment)—to let the user know why the **Disable** task is not available. Most items should not set this value.

### `SYNCMGR_IPM_PREVENT_START_SYNC:0x4`

Starting a sync through the user interface or through the APIs is not supported. Sync can be started only by an external application that creates a session creator to report progress. If this value is set, then the Start Sync task will not be shown in the handler's folder when the sync item is selected. Note that Start Sync must be supported on a handler in order for it to be supported on a sync item. Most sync items should not set this value.

### `SYNCMGR_IPM_PREVENT_STOP_SYNC:0x8`

Stopping a sync through the user interface or through the APIs is not supported. If this value is set, the Stop Sync task is not shown in the handler's folder when the sync item is selected. Note that Stop Sync must be supported on a handler in order for it to be supported on a sync item. Most sync items should not set this value.

### `SYNCMGR_IPM_DISABLE_ENABLE:0x10`

The enable task should be disabled when it is shown for this sync item. With this policy set, the **Enable** option appears in the context menu, if SYNCMGR_IPM_PREVENT_ENABLE is not set, but is disabled.

### `SYNCMGR_IPM_DISABLE_DISABLE:0x20`

The disable task should be disabled when it is shown for this sync item. With this policy set, the **Disable** option appears in the context menu, if SYNCMGR_IPM_PREVENT_DISABLE is not set, but is disabled.

### `SYNCMGR_IPM_DISABLE_START_SYNC:0x40`

The Start Sync task should be disabled when it is shown for this sync item. With this policy set, the **Start Sync** option appears in the context menu, if SYNCMGR_IPM_PREVENT_START_SYNC is not set and if SYNCMGR_HPM_PREVENT_START_SYNC is not set on the handle, but is disabled.

### `SYNCMGR_IPM_DISABLE_STOP_SYNC:0x80`

The **Stop Sync** task should be disabled when it is shown for this sync item. With this policy set, the **Stop Sync** option appears in the context menu, if SYNCMGR_IPM_PREVENT_STOP_SYNC is not set and if SYNCMGR_HPM_PREVENT_STOP_SYNC is not set on the handler, but is disabled.

### `SYNCMGR_IPM_DISABLE_BROWSE:0x100`

The **Browse** task should be disabled when it is shown for this sync item. The **Browse** task is shown only if the SYNCMGR_ICM_CAN_BROWSE_CONTENT value is returned from the [ISyncMgrSyncItem::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities) method.

### `SYNCMGR_IPM_DISABLE_DELETE:0x200`

The handler normally supports deleting items, but that this item cannot be deleted at the time of the call. With this policy set, the **Delete** option appears as disabled in the context menu for the sync item.

### `SYNCMGR_IPM_HIDDEN_BY_DEFAULT:0x10000`

The item should be hidden from the user unless the **Show Hidden Files** option has been enabled. This policy only applies the first time the item is loaded. After that, the hidden state is maintained by Sync Center and can be changed by the user through the property sheet.

### `SYNCMGR_IPM_VALID_MASK:0x102ff`

A mask used to retrieve valid [SYNCMGR_ITEM_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_policies) flags.