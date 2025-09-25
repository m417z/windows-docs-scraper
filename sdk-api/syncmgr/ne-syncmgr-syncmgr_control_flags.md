# SYNCMGR_CONTROL_FLAGS enumeration

## Description

Specifies how an operation requested on certain methods of [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol) should be performed.

## Constants

### `SYNCMGR_CF_NONE:0`

Perform the operation not using any of the other flags in this enumeration.

### `SYNCMGR_CF_NOWAIT:0`

Perform the operation asynchronously.

### `SYNCMGR_CF_WAIT:0x1`

Perform the operation synchronously.

### `SYNCMGR_CF_NOUI:0x2`

Perform the operation without asking the sync handler to display the UI during the operation.

### `SYNCMGR_CF_VALID:0x3`

A mask used to determine valid [SYNCMGR_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_control_flags) flags.