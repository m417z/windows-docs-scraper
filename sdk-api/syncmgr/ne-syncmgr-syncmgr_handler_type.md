# SYNCMGR_HANDLER_TYPE enumeration

## Description

Specifies the type of a handler. Used by [ISyncMgrHandlerInfo::GetType](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-gettype).

## Constants

### `SYNCMGR_HT_UNSPECIFIED:0`

The handler type is unknown. This value is also used if [ISyncMgrHandlerInfo::GetType](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-gettype) fails.

### `SYNCMGR_HT_APPLICATION:1`

The handler is an application.

### `SYNCMGR_HT_DEVICE:2`

The handler syncs with a device such as a phone or PDA.

### `SYNCMGR_HT_FOLDER:3`

The handler syncs with local or remote folders.

### `SYNCMGR_HT_SERVICE:4`

The handler syncs with a web service.

### `SYNCMGR_HT_COMPUTER:5`

The handler syncs with a computer.

### `SYNCMGR_HT_MIN:0`

Indicates the minimum [SYNCMGR_HANDLER_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type) value.

### `SYNCMGR_HT_MAX`

Indicates the maximum [SYNCMGR_HANDLER_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type) value.