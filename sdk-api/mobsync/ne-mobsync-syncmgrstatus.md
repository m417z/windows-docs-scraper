# SYNCMGRSTATUS enumeration

## Description

Used in the [ISyncMgrSynchronize::SetItemStatus](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-setitemstatus) method to specify the updated status for the item.

## Constants

### `SYNCMGRSTATUS_STOPPED:0`

Synchronization has been stopped.

### `SYNCMGRSTATUS_SKIPPED:0x1`

Indicates that this item should be skipped.

### `SYNCMGRSTATUS_PENDING:0x2`

Synchronization for the item is pending.

### `SYNCMGRSTATUS_UPDATING:0x3`

The item is currently being synchronized.

### `SYNCMGRSTATUS_SUCCEEDED:0x4`

The synchronization for the item succeeded.

### `SYNCMGRSTATUS_FAILED:0x5`

Synchronization for the item failed.

### `SYNCMGRSTATUS_PAUSED:0x6`

Synchronization for the item paused.

### `SYNCMGRSTATUS_RESUMING:0x7`

Synchronization for the item is resuming.

### `SYNCMGRSTATUS_UPDATING_INDETERMINATE:0x8`

**Windows Vista and later**. Shows marquee progress for the synchronized item. Sets the progress bar in the folder to marquee the synchronization progress.

### `SYNCMGRSTATUS_DELETED:0x100`

The item has been deleted. This value has been deprecated for Windows Vista and later.

## See also

[ISyncMgrSynchronize::SetItemStatus](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-setitemstatus)