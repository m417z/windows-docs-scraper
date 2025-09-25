# IOfflineFilesEvents::SyncConflictRecUpdated

## Description

Reports that a sync conflict has been detected and that a record of the conflict was already present in the sync conflict log. The log's record has been updated with the latest information.

## Parameters

### `pszConflictPath` [in]

The UNC path of the item in conflict.

### `pftConflictDateTime` [in]

Pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the date and time when the conflict was detected. The value is in UTC.

### `ConflictSyncState` [in]

Describes the state of the local and remote items in conflict. One of the [OFFLINEFILES_SYNC_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_state) sync state values, such as

OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer

.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)