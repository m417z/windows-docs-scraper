# SYNCMGR_RESOLUTION_FEEDBACK enumeration

## Description

Describes Sync Manager resolution feedback. Used by [ISyncMgrResolutionHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrresolutionhandler).

## Constants

### `SYNCMGR_RF_CONTINUE:0`

Proceed to the next conflict.

### `SYNCMGR_RF_REFRESH`

**Apply to All** is stopped and the dialog will be displayed for this conflict.

### `SYNCMGR_RF_CANCEL`

 Cancels resolution of any more conflicts in the set.