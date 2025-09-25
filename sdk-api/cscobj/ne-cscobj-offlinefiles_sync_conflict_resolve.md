# OFFLINEFILES_SYNC_CONFLICT_RESOLVE enumeration

## Description

Identifies the conflict resolution code returned by the [IOfflineFilesSyncConflictHandler::ResolveConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncconflicthandler-resolveconflict) method.

## Constants

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NONE:0`

No resolution. The conflict is unresolved. This allows the conflict to be processed by other handlers in the system.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLOCAL`

Keep the local state. This overwrites the remote copy with the local copy's contents. If the local copy was deleted, this deletes the remote copy on the server.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPREMOTE`

Keep the remote state. This overwrites the local copy with the remote copy's contents. If the remote copy was deleted, this deletes the local copy in the Offline Files cache.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES`

Keeps both copies. Note that this resolution is valid only for sync conflict states where both the server and client copies exist and where at least one of the items is a file. The **OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES** resolution is not available when one of the items has been deleted or both items are directories.

The list of applicable [OFFLINEFILES_SYNC_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_state) values is as follows:

**OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileChangedOnServer**
**OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileOnServer**
**OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileChangedOnServer**
**OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileOnServer**
**OFFLINEFILES_SYNC_STATE_DirOnClient_FileChangedOnServer**
**OFFLINEFILES_SYNC_STATE_DirOnClient_FileOnServer**
**OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer**
**OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirChangedOnServer**
**OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirOnServer**
**OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirChangedOnServer**
**OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirOnServer**
**OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileChangedOnServer**
**OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileOnServer**
**OFFLINEFILES_SYNC_STATE_FileOnClient_DirOnServer**

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLATEST`

Retains the state of the latest operation as determined by last-change times of the items in conflict. If the local item was deleted, the time of deletion is used for comparison.

The case where the remote copy was deleted after the client copy was changed is a special case that produces an unexpected result. The logical expectation is that the later operation (the remote deletion) propagates to the client and deletes the client copy from the cache. However, the result is that the client copy is restored to the server, reversing the deletion. This is because Offline Files is a client feature and therefore is unable to know when a remote copy of a cached item was deleted. If the local copy is modified offline, the last-change time of that local copy will be later than the last-change time for the remote copy recorded when the item was last in sync. Therefore, an **OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLATEST** resolution finds the last-change time on the client copy to be later than the last-change time last known for the server copy. This causes the local copy to be restored to the server.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LOG`

Write an entry to the sync conflict log and perform no further attempts at resolving the conflict. The interactive user will resolve the conflict through Sync Center at a later time.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_SKIP`

Do not resolve the conflict. Do not record an entry in the sync conflict log.

### `OFFLINEFILES_SYNC_CONFLICT_ABORT`

Cancel the synchronization operation.

### `OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NUMCODES`

## See also

[IOfflineFilesSyncConflictHandler::ResolveConflict](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncconflicthandler-resolveconflict)

[OFFLINEFILES_SYNC_STATE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_state)