# SYNCMGR_SYNC_CONTROL_FLAGS enumeration

## Description

Indicates flags used by [ISyncMgrControl::StartHandlerSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-starthandlersync) and [ISyncMgrControl::StartItemSync](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-startitemsync).

## Constants

### `SYNCMGR_SCF_NONE:0`

Sync all items, regardless of whether they were just synced.

### `SYNCMGR_SCF_IGNORE_IF_ALREADY_SYNCING:0x1`

Sync only items that are not currently syncing.

### `SYNCMGR_SCF_VALID:0x1`

A mask used to retrieve or verify valid [SYNCMGR_SYNC_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_sync_control_flags) flags.

## Remarks

 Typically, sync requests are queued if a synchronization is currently in progress. An item might be in both the ongoing synchronization and the queued synchronization. These flags specify whether such an item should be resynched when the queued synchronization is performed.