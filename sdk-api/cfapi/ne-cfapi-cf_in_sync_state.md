# CF_IN_SYNC_STATE enumeration

## Description

Specifies the in-sync state for placeholder files and folders.

## Constants

### `CF_IN_SYNC_STATE_NOT_IN_SYNC:0`

The platform clears the placeholder’s in-sync state upon a successful return from the [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) call.

### `CF_IN_SYNC_STATE_IN_SYNC:1`

The platform sets the placeholder’s in-sync state upon a successful return from the [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) call.

## See also

[CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate)