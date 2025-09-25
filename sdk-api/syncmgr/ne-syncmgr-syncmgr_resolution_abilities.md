# SYNCMGR_RESOLUTION_ABILITIES enumeration

## Description

Indicates abilities and the conflict resolution activity to follow. Used with [ISyncMgrResolutionHandler::QueryAbilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-queryabilities).

## Constants

### `SYNCMGR_RA_KEEPOTHER:0x1`

The resolution handler supports merging items and will produce a merged file to keep.

### `SYNCMGR_RA_KEEPRECENT:0x2`

Enables methods [ISyncMgrResolutionHandler::KeepRecent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-keeprecent) and [ISyncMgrResolutionHandler::KeepOther](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-keepother) to be called.

### `SYNCMGR_RA_REMOVEFROMSYNCSET:0x4`

Enables method [ISyncMgrResolutionHandler::RemoveFromSyncSet](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-removefromsyncset) to be called.

### `SYNCMGR_RA_KEEP_SINGLE:0x8`

Not used.

### `SYNCMGR_RA_KEEP_MULTIPLE:0x10`

Enables method [ISyncMgrResolutionHandler::KeepItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-keepitems) to be called with more than one item in *pArray*.

### `SYNCMGR_RA_VALID:0x1f`

A mask for valid [SYNCMGR_RESOLUTION_ABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_abilities) values.