# SYNCMGR_PROGRESS_STATUS enumeration

## Description

Specifies the current progress status of a synchronization process. Used by [ISyncMgrSyncCallback::ReportProgress](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportprogress).

## Constants

### `SYNCMGR_PS_UPDATING:1`

The progress status is currently being updated by the handler.

### `SYNCMGR_PS_UPDATING_INDETERMINATE:2`

Ignore step parameters. The progress bar cycles from left to right on a timer internal to the sync folder. This is known as marquee mode.

### `SYNCMGR_PS_SUCCEEDED:3`

The synchronization is complete.

### `SYNCMGR_PS_FAILED:4`

Indicates something went wrong during the synchronization.

### `SYNCMGR_PS_CANCELED:5`

The user canceled the synchronization before it completed. Upon receipt of this value, Sync Center updates the UI and enables the option to restart the sync for that item.

### `SYNCMGR_PS_DISCONNECTED:6`

The device being synchronized was disconnected before the sync completed..

### `SYNCMGR_PS_MAX`

Used only to declare the largest valid value in this enumeration. Do not use with [ISyncMgrSyncCallback::ReportProgress](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportprogress).