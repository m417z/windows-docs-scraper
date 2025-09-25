# IOfflineFilesEvents::SyncConflictRecRemoved

## Description

Reports that a sync conflict no longer exists and that its record has been removed from the sync conflict log.

## Parameters

### `pszConflictPath` [in]

The UNC path of the item that was in conflict.

### `pftConflictDateTime` [in]

Pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the date and time when the deleted conflict was detected. The value is in UTC.

### `ConflictSyncState` [in]

Describes the state of the local and remote items in conflict. One of the [OFFLINEFILES_SYNC_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_state) sync state values, such as

OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer

.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)