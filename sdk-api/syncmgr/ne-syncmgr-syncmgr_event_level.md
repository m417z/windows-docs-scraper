# SYNCMGR_EVENT_LEVEL enumeration

## Description

Specifies the type of event being reported to Sync Center.

## Constants

### `SYNCMGR_EL_INFORMATION:1`

The event is informational in nature and will be displayed with the appropriate icon.

### `SYNCMGR_EL_WARNING:2`

The event is a warning and will be displayed with the appropriate icon.

### `SYNCMGR_EL_ERROR:3`

The event is an error and will be displayed with the appropriate icon. Additionally, this event will be included in the count of errors reported to the handler or item when it is displayed in the folder as well as to the sync tray icon.

### `SYNCMGR_EL_MAX`

Used only to declare the largest valid value in this enumeration. Do not use with [ISyncMgrSyncCallback::ReportEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportevent).